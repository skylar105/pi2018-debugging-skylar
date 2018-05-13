#include "debugging.h"

/* Takes in a pointer to a date string and sets it to the current date/time in ISO 8601 format */
void date_iso8601(char *DATE_STRING) {
    time_t t;
    struct tm *tmp;

    if((t = time(NULL)) == -1) {
        DEBUG_OUTPUT("time(NULL) failed: %s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }

    if((tmp = localtime(&t)) == NULL) {
        DEBUG_OUTPUT("localtime failed: %s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }

    if((strftime(DATE_STRING,DATE_ISO8601_BYTES,"%Y-%m-%dT%H:%M:%S%z",tmp)) == 0) {
        DEBUG_OUTPUT("strftime failed: %s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }
}

/* Takes in a number of bytes, and a calling file name and line number */
/* Returns a pointer to an array of that size, or exits with failure */
void *safe_malloc(const size_t bytes,const char *file,const int line) {
    char *byte_array;

#ifdef DEBUG
    DEBUG_OUTPUT("Allocating array of %zd bytes for %s:%d\n",
            bytes,
            file,
            line
           );
#endif
    if((byte_array = (char *)malloc(sizeof(char) * bytes)) == NULL) {
        DEBUG_OUTPUT("malloc(%zd) failed at %s:%d: %s\n",
                bytes,
                file,
                line,
                strerror(errno)
               );
        exit(EXIT_FAILURE);
    }

    return byte_array;
}
