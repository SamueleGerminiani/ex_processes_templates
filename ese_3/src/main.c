#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "errExit.h"


int main(int argc, char *argv[]) {
    // Get the username of the current user using 'getenv'

    // Get the home directory of the user using 'getenv'

    // Get the current process's working directory using 'getcwd'

    // Check if the current process's working directory is a subdirectory of
    // the user's home directory using 'strncmp'

    if (1 /*change this*/) {
        // printf("Dear %s, I am already in the right place!\n", username);
    } else {
        // Move the process into the user's home directory using 'chdir'

        // Create an empty file using 'open'

        // Close the file descriptor of the empty file using 'close'

        // printf("Dear %s, I am now inside your home directory!\n", username);
    }

    return 0;
}

