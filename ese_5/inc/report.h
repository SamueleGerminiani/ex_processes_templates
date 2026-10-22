#ifndef _REPORT_HH
#define _REPORT_HH

/* Case report code: you do not need to read or modify this file :)
 *
 * report_check reveals code #5 when the error messages of "ls /nonexistent"
 * end up in the log file. The code is bound to the current user and machine.
 */
void report_check(const char *command, int status, const char *logFile);

#endif
