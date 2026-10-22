/* Demo 6 - where does printf write? Follow file descriptor 1.
 * In a second terminal: ls -l /proc/<PID>/fd */
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "errExit.h"

/* Case report, code #1: written at the end of the log file. */
static const char *code1(void) {
    static char word[8];
    const char enc[] = {0x0f, 0x0d, 0x17, 0x0c, 0x0c, 0x08, 0x00};
    for (int i = 0; i < 7; i++)
        word[i] = enc[i] ^ ('a' + i);
    word[7] = '\0';
    return word;
}

int main(int argc, char *argv[]) {
    printf("redirect_demo: PID %d\n", getpid());
    printf("look at /proc/%d/fd now (15 seconds)...\n", getpid());
    sleep(15);
    fflush(stdout);   // printf buffers are flushed before fd 1 is closed

    // FDT: [0, 1, 2] -> [0, 2]
    close(STDOUT_FILENO);
    // The lowest free index is 1: the file becomes the new standard output
    int fd = open("demo.log", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        errExit("open");
    // FDT: [0, 1, 2] -> [0, 1]
    close(STDERR_FILENO);
    // dup returns the lowest free index: 2. Now stderr is the file too
    if (dup(fd) == -1)
        errExit("dup");

    printf("this line goes to the file (fd %d)\n", fd);
    fflush(stdout);
    fprintf(stderr, "and so does this error message\n");
    fprintf(stderr, "look at /proc/%d/fd again (15 seconds)...\n", getpid());
    sleep(15);

    printf("Case report, code #1: \"%s\"\n", code1());
    return 0;
}
