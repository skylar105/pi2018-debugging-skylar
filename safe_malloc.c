/*
 * Demonstrates the use of a malloc routine that will exit when the allocation fails.
 * Takes in an optional command line argument for the number of integer elements in the array,
 * otherwise defaults to 500.
 * 
 * If built with the compiler declaration DEBUG, prints out debug messages to STDERR as well.
 *
 */

#include "debugging.h"

int main(int argc, char **argv) {
    int *array;
    unsigned int i;
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

    // Call the SAFE_MALLOC preprocessor macro with the number of bytes to allocate
    array = (int *)SAFE_MALLOC(sizeof(int)*array_size);

    for(i=0;i<array_size;i++) {
        array[i] = i;
    }

    free(array);
#ifdef DEBUG
    free(DATE_STRING);
#endif

    exit(EXIT_SUCCESS);
}
