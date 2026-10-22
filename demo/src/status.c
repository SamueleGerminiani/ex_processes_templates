/* Demo 4 - the exit status travels from the child to the parent (wait)
 * and from the parent to the shell (echo $?). */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "errExit.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <exit code of the child>\n", argv[0]);
        return 1;
    }
    int code = atoi(argv[1]);

    pid_t pid = fork();
    if (pid == -1)
        errExit("fork");

    if (pid == 0) {
        printf("child %d: exiting with code %d\n", getpid(), code);
        exit(code);
    }

    int status;
    if (wait(&status) == -1)
        errExit("wait");

    if (WIFEXITED(status))
        printf("parent: the child exited with status %d\n", WEXITSTATUS(status));

    // The parent returns the same code: check it with echo $?
    return WEXITSTATUS(status);
}
