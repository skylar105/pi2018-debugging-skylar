/*
 * Demonstrates malloc problems for debug demonstration.
 * 
 * If built with the compiler declaration DEBUG, prints out debug messages to STDERR as well.
 *
 */

#include "debugging.h"

void do_something_bad(const size_t array_size,int *array) {
    size_t stride = 1000;
    unsigned int i;

    for(i=0;i<array_size*stride;i++) {
        array[i] = i;
    }

    printf("array[%zd] = %d\n",array_size*stride,array[array_size*stride]);
}

int main(int argc, char **argv) {
    int *array;
    // Default array size to 500
    size_t array_size = 500;

#ifdef DEBUG
    DATE_STRING = SAFE_MALLOC(DATE_ISO8601_BYTES);
#endif

    // Set array size to user specified value if available
    if(argc == 2) {
        // Clear previous errno setting
        errno = 0;
        array_size = strtoul(argv[1],NULL,10);
        if(errno != 0) {
            DEBUG_OUTPUT("Invalid array size %s: %s\n",
                    argv[1],
                    strerror(errno)
                   );
            exit(EXIT_FAILURE);
        }
    }

#ifdef DEBUG
    DEBUG_OUTPUT("Array size is %zd\n",array_size);
#endif

    // Use malloc rather than SAFE_MALLOC for easier debugging
    if((array = (int *)malloc(sizeof(int)*array_size)) == NULL) {
        fprintf(stderr,"malloc failed: %s, %s:%d\n",
                strerror(errno),
                __FILE__,
                __LINE__
                );
        exit(EXIT_FAILURE);
    }

    do_something_bad(array_size,array);

    free(array);
#ifdef DEBUG
    free(DATE_STRING);
#endif

    exit(EXIT_SUCCESS);
}
