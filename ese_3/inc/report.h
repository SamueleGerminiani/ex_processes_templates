#ifndef _REPORT_HH
#define _REPORT_HH

/* Case report code: you do not need to read or modify this file :)
 *
 * report_check reveals code #3 when the process, started outside the
 * home directory, has moved into it and created marker.txt there as
 * requested. startDir is the working directory read before moving.
 * The code is bound to the current user and machine.
 */
void report_check(const char *homeDir, const char *startDir);

#endif
