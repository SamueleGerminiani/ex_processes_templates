/* Demo 2 - a child that terminates before the parent calls wait.
 * In a second terminal: ps ax | grep zombie_demo */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "errExit.h"

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if (pid == -1)
        errExit("fork");

    if (pid == 0) {
        printf("child %d: done, exiting now\n", getpid());
        exit(0);
    }

    printf("parent %d: the child %d is dead but I have not called wait yet\n",
           getpid(), pid);
    printf("parent %d: look at ps in the next 20 seconds...\n", getpid());
    sleep(20);

    if (wait(NULL) == -1)
        errExit("wait");
    printf("parent %d: wait done, the child is gone from the process table\n",
           getpid());
    printf("parent %d: look at ps again (10 seconds)\n", getpid());
    sleep(10);

    return 0;
}
