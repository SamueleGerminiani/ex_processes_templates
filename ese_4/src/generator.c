#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <unistd.h>

#include "errExit.h"

#define MAX_NUM 100

int main(int argc, char *argv[]) {

    // Initialize seed for 'rand' function using 'srand' and 'time'
    srand(0);

    // Generate two random numbers between 0 and MAX_NUM

    // Create character arrays to store the converted random numbers as strings
    char nStr[100];
    char mStr[100];

    // Convert the two random numbers to strings using 'sprintf'

    // Execute the "moltiplicatore" program with the converted random numbers as arguments using 'execl'


    // If execl fails, print an error message using 'errExit'

    // This return statement will not be reached if execl succeeds
    return 1;
}

