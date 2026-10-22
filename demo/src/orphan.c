/* Demo 3 - a child that outlives its parent: who is its parent now? */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "errExit.h"

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if (pid == -1)
        errExit("fork");

    if (pid == 0) {
        for (int i = 0; i < 4; i++) {
            printf("child %d: my parent is %d\n", getpid(), getppid());
            sleep(2);
        }
        exit(0);
    }

    printf("parent %d: exiting now, the child %d is on its own\n", getpid(), pid);
    return 0;
}
