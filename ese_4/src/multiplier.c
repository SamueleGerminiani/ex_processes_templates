#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "report.h"

int main(int argc, char *argv[]) {
    // Check command line input arguments using 'argc'
    if (argc != 3) {
        printf("Usage: %s <n> <m>\n", argv[0]);
        return 1;
    }

    // Convert argv[1] and argv[2] to the integers n and m using 'atoi'
    int n = 0;
    int m = 0;

    // Print "The product of <n> and <m> is: <n*m>"


    // Print "multiplier: PID <pid>, started by generator <GENERATOR_PID>"
    // reading the variable GENERATOR_PID from the environment using 'getenv'
    // and the PID using 'getpid'
    char *generatorPid = NULL;


    // Case report (given): reveals code #4 if the two PIDs are the same
    report_check(generatorPid, getpid());
    return 0;
}
