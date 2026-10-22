#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include "errExit.h"

#define BUFFER_SZ 4096

int main(int argc, char *argv[]) {
    // Get the username of the current user using 'getenv' (variable USER)
    char *username = NULL;
    if (username == NULL)
        username = "unknown";

    // Get the home directory of the user using 'getenv' (variable HOME)
    char *homeDir = NULL;
    if (homeDir == NULL) {
        printf("Unknown home directory\n");
        return 1;
    }

    // Get the current working directory of the process using 'getcwd'
    char buffer[BUFFER_SZ];


    printf("Working directory: %s\n", buffer);

    // Check whether the working directory is inside the home directory,
    // i.e. whether it starts with homeDir, using 'strncmp' and 'strlen'
    int inside = 0;

    if (inside) {
        printf("Dear %s, I am already in the right place!\n", username);
    } else {
        // Move the process into the home directory using 'chdir'
        // (use 'errExit' if it fails)


        // Create the empty file "marker.txt" using 'open' with the flags
        // O_CREAT | O_WRONLY | O_TRUNC and mode S_IRUSR | S_IWUSR
        // (use 'errExit' if it fails)
        int fd = -1;

        // Close the file descriptor using 'close'


        printf("Dear %s, I am inside your home!\n", username);
    }

    return 0;
}
