#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

#include "errExit.h"

#define MAX_NUM 100

int main(int argc, char *argv[]) {
    // Initialize the random generator using 'srand' and 'time'
    srand(time(NULL));

    // Generate two random numbers n and m between 0 and MAX_NUM using 'rand'
    int n = 0;
    int m = 0;

    printf("generator: PID %d, numbers %d and %d\n", getpid(), n, m);

    // Store the PID of this process in the environment variable
    // GENERATOR_PID using 'sprintf' and 'setenv'
    char pidStr[32];


    // Convert n and m to strings using 'sprintf'
    char nStr[32];
    char mStr[32];


    // Replace this program with "./multiplier" using 'execl', passing
    // the two strings as command-line arguments


    // If exec fails, print an error message using 'errExit'

    return 1;
}
