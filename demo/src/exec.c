/* Demo 5 - exec replaces the program, not the process. */
#include <stdio.h>
#include <unistd.h>

#include "errExit.h"

int main(int argc, char *argv[]) {
    printf("exec_demo: PID %d, about to run ./hello\n", getpid());

    // The argument list ends with (char *) NULL
    execl("./hello", "hello", "from", "exec_demo", (char *) NULL);

    // Only reached if execl fails (e.g. ./hello does not exist)
    errExit("execl");
    printf("this line is never printed\n");
    return 0;
}
