#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "errExit.h"
#include "report.h"

int main(int argc, char *argv[]) {
    // Check command line input arguments using 'argc'
    if (argc != 2) {
        printf("Usage: %s <seconds of work>\n", argv[0]);
        return 1;
    }

    // Convert argv[1] to an integer using 'atoi': the duration of the work
    int seconds = 0;

    // Create the worker process using 'fork'
    pid_t pid = -1;

    if (1 /*change this*/) {
        // fork failed: print a message using 'errExit'

    } else if (1 /*change this*/) {
        // Worker: print "worker <pid>: working for <seconds> seconds",
        // simulate the work using 'sleep', then print "worker <pid>: done"
        // and terminate using 'exit' with code 0

    }

    // Monitor (parent): print "monitor: watching worker <pid>"


    // Poll the worker using 'waitpid' and 'WNOHANG': while the worker is
    // still running, print a "." (use 'fflush(stdout)' to see it
    // immediately) and 'sleep' for 1 second. Stop when waitpid returns
    // the pid of the worker. Use 'errExit' if waitpid fails.
    int status = 0;
    while (1 /*change this*/) {

    }
    printf("\n");

    // Report how the worker terminated:
    //  - if it exited ('WIFEXITED'):
    //        "monitor: worker <pid> exited with status <WEXITSTATUS>"
    //  - if it was killed by a signal ('WIFSIGNALED'):
    //        "monitor: worker <pid> killed by signal <WTERMSIG> (<strsignal>)"


    // Case report (given): reveals code #3 when the worker is terminated
    report_check(status);
    return 0;
}
