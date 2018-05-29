CC = gcc
# Use -g3 (rather than default -g2) to get preprocessor definitions
CFLAGS = -Wall # -gstabs+ -g3 -O0
EXPENDABLES = safe_malloc unsafe_malloc debugging.o

# Make sure to run "make clean" to rebuild debugging.o if you change the DEBUG mode
ifeq ($(DEBUG),1)
	CFLAGS += -DDEBUG
endif

.PHONY: clean

debugging.o: debugging.h debugging.c

safe_malloc: safe_malloc.c debugging.o debugging.h
	$(CC) $(CFLAGS) $< debugging.o -o $@

unsafe_malloc: unsafe_malloc.c debugging.o debugging.h
	$(CC) $(CFLAGS) $< debugging.o -o $@

clean:
	/bin/rm -f $(EXPENDABLES)
