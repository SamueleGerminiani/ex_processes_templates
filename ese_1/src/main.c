#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "errExit.h"
#include "report.h"

int main(int argc, char *argv[]) {
    // Check command line input arguments using 'argc'
    if (argc != 2) {
        printf("Usage: %s <number of child processes>\n", argv[0]);
        return 1;
    }

    // Convert argv[1] to an integer using 'atoi'.
    // This integer is the number of child processes to create.
    int n = 0;
    if (n <= 0) {
        printf("The number of child processes must be greater than 0!\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        // Draw the exit code of the next child: a random number in [0, 255]
        // using 'rand' (do not call 'srand': runs must be reproducible)
        int code = 0;

        // Create a child process using 'fork'
        pid_t pid = -1;

        if (1 /*change this*/) {
            // fork failed: print a message using 'errExit'

        } else if (1 /*change this*/) {
            // Child process: print "child <i>: PID <pid>, PPID <ppid>,
            // exit code <code>" using 'getpid' and 'getppid'

            // Terminate the child with 'exit' and the drawn code

        }
        // Parent process: keep creating children
    }

    // Parent process: wait for the termination of every child using 'wait'.
    // For each terminated child print "child <pid> terminated with code <code>"
    // using 'WEXITSTATUS', and add the code to 'sum'.
    int sum = 0;
    while (1 /*change this*/) {

    }

    printf("all %d children terminated, sum of the exit codes: %d\n", n, sum);

    // Case report (given): reveals code #1 with 10 children
    report_check(n, sum);
    return 0;
}
