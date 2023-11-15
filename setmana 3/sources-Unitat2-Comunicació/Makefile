CC=gcc

RM=rm

CFLAGS=-c -fopenmp -Wall -O3 -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion


LDFLAGS=-fopenmp

SOURCES=$(wildcard *.c)

OBJECTS=$(SOURCES:.c=.o)

EXECS=$(SOURCES:%.c=%)


.PHONY: all
all: $(OBJECTS) $(EXECS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@ 

.o.: 
	$(CC) $^ $(LDFLAGS)  $< -o  $@ 


.PHONY: clean
clean:
	-@ $(RM) *.o 
	-@ $(RM) $(EXECS)