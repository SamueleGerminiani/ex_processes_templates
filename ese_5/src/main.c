#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "errExit.h"
#include "report.h"

const char *logFile = "output.log";

int main(int argc, char *argv[]) {
    // Check command line input arguments using 'argc'
    if (argc < 2) {
        printf("Usage: %s <command> [arguments...]\n", argv[0]);
        return 1;
    }

    // Create a child process using 'fork'
    pid_t pid = -1;

    if (1 /*change this*/) {
        // fork failed: print a message using 'errExit'

    } else if (1 /*change this*/) {
        // Child process:

        // Close the standard output and the standard error
        // ('STDOUT_FILENO' and 'STDERR_FILENO') using 'close'


        // Create/truncate the log file using 'open' with the flags
        // O_WRONLY | O_CREAT | O_TRUNC and mode S_IRUSR | S_IWUSR.
        // What file descriptor do you get? (use 'errExit' if it fails)
        int fd = -1;

        // Duplicate it using 'dup'. What file descriptor do you get?


        // Replace the child with the command using 'execvp'
        // (the command and its arguments start at argv[1])


        // If exec fails, print an error message using 'errExit'

    }

    // Parent process: wait for the termination of the child using 'wait'
    // (use 'errExit' if it fails)
    int status = 0;


    // Print "command <command> terminated with status <WEXITSTATUS>"
    // if the child exited ('WIFEXITED'), otherwise
    // "command <command> killed by signal <WTERMSIG>"


    // Case report (given): reveals code #5 when the error messages of the
    // command end up in the log file
    report_check(argv[1], status, logFile);
    return 0;
}
