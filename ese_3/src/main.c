#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include "errExit.h"
#include "report.h"

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
    // (use 'errExit' if it fails)
    char buffer[BUFFER_SZ] = "";


    printf("Working directory: %s\n", buffer);

    // Check whether the working directory is inside the home directory,
    // i.e. whether it starts with homeDir, using 'strncmp' and 'strlen'
    int inside = 0;

    if (inside) {
        printf("Dear %s, I am already in the right place!\n", username);
        return 0;
    }

    // Bookmark the start directory: open "." with O_RDONLY and keep the
    // file descriptor (use 'errExit' if it fails)
    int startFd = -1;

    // Move the process into the home directory using 'chdir'
    // (use 'errExit' if it fails)


    // Create the empty file "marker.txt" using 'open' with the flags
    // O_CREAT | O_WRONLY | O_TRUNC and mode S_IRUSR | S_IWUSR
    // (use 'errExit' if it fails)
    int fd = -1;

    // Close the file descriptor of marker.txt using 'close'


    printf("Dear %s, I left a marker in your home!\n", username);

    // Return to the start directory using 'fchdir' on the bookmark
    // (use 'errExit' if it fails), then close the bookmark using 'close'


    // Read the working directory again using 'getcwd' and print
    // "Back in <directory>"


    // Case report (given): reveals code #3 after the round trip
    report_check(homeDir, buffer);
    return 0;
}
