/* The program started by exec_demo: a different program, the same PID. */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("hello: PID %d, PPID %d\n", getpid(), getppid());
    for (int i = 0; i < argc; i++)
        printf("hello: argv[%d] = %s\n", i, argv[i]);
    return 0;
}
