/* Demo 1 - one process becomes two.
 *   ./fork_demo      one line each: the parent almost always prints first
 *   ./fork_demo 8    eight lines each: the two processes run side by side
 *                    and their lines interleave differently at every run */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "errExit.h"

/* A few milliseconds of CPU work between two lines */
static void work(void) {
  for (volatile long k = 0; k < 20000000L; k++)
    ;
}

int main(int argc, char *argv[]) {
  int lines = (argc > 1) ? atoi(argv[1]) : 1;

  printf("before fork: PID %d\n", getpid());
  fflush(stdout);  // the printf buffer is not duplicated by fork

  pid_t pid = fork();
  if (pid == -1) errExit("fork");

  // --> both the parent and the child continue from here <--
  for (int i = 1; i <= lines; i++) {
    if (pid == 0)
      printf("child : PID %d, my parent is %d (line %d)\n", getpid(), getppid(),
             i);
    else
      printf("parent: PID %d, my child is %d (line %d)\n", getpid(), pid, i);
    fflush(stdout);
    work();
  }

  if (pid != 0) {
    if (wait(NULL) == -1) errExit("waitpid");
  }

  return 0;
}
