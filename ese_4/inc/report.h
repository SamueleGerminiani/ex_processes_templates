#ifndef _REPORT_HH
#define _REPORT_HH

#include <sys/types.h>

/* Case report code: you do not need to read or modify this file :)
 *
 * report_check reveals code #4 when the PID stored by the generator is the
 * PID of the multiplier. The code is bound to the current user and machine.
 */
void report_check(const char *generatorPid, pid_t pid);

#endif
