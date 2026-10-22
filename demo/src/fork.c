/* Demo 1 - one process becomes two.
 * Run it a few times: the order of the two lines is not fixed. */
#include <stdio.h>
#include <unistd.h>

#include "errExit.h"

int main(int argc, char *argv[]) {
    printf("before fork: PID %d\n", getpid());

    pid_t pid = fork();
    if (pid == -1)
        errExit("fork");

    // --> both the parent and the child continue from here <--
    if (pid == 0)
        printf("child : PID %d, my parent is %d\n", getpid(), getppid());
    else
        printf("parent: PID %d, my child is %d\n", getpid(), pid);

    return 0;
}
