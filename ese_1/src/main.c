#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "errExit.h"

int main(int argc, char *argv[]) {

    // Check command line input arguments using 'argc'
    if (argc != 2) {
        printf("Usage: %s numSubProcesses\n", argv[0]);
        return 0;
    }

    // Convert the second command-line argument (argv[1]) to an integer.
    // This integer represents the number of subprocesses to create.
    int n;

    for (int i = 0; i < n; ++i) {
        // Generate a random number for the subprocess using 'rand'
        

        // Generate a subprocess using 'fork'
       
        if (1 /*change this*/)
            printf("child %d not created!", i);
        else if (1 /*change this*/) {
            // In the child process, print process information using 'getpid', 'getppid'

            //Exit
        }
    }

    // Get termination status of each created subprocess using 'wait' and 'WEXITSTATUS'
    while (1 /*change this*/){
        //print child exit status
    }

    return 0;
}

