/* $Id: debugging.h 5959 2017-05-19 03:25:19Z skylar $ */

#ifndef DEBUGGING_H
#define DEBUGGING_H

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Wrap the safe_malloc function to include file and line number
#define SAFE_MALLOC(bytes) safe_malloc(bytes,__FILE__,__LINE__)

void *safe_malloc(const size_t,const char *,const int);

// Hard-code the length of a ISO8601 date/time string to 26 bytes
#define DATE_ISO8601_BYTES 26
// Global variable holding the current date/time
char *DATE_STRING;
void date_iso8601(char *);
#define DEBUG_OUTPUT(format,...) { \
    date_iso8601(DATE_STRING); \
    fprintf(stderr,"%s: ",DATE_STRING); \
    fprintf(stderr,format,__VA_ARGS__); \
}

#endif /* DEBUGGING_H */
