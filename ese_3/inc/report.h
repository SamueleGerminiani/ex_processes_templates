#ifndef _REPORT_HH
#define _REPORT_HH

/* Case report code: you do not need to read or modify this file :)
 *
 * report_check reveals code #3 when the process, started outside the
 * home directory, has created marker.txt in it and has come back to the
 * start directory. startDir is the working directory read at the start.
 * The code is bound to the current user and machine.
 */
void report_check(const char *homeDir, const char *startDir);

#endif
