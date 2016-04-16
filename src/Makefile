
# Cody Barnson
# makefile for sudoku solver

# declaration of variables
CC = g++11
CCFLAGS = -Wall -g -std=c++11 

# file names
SOURCES = $(wildcard *.cc)
OBJECTS = $(SOURCES:.cc=.o)
LIBDIR = 
LNFLAGS =

# main target
all: main

main: $(OBJECTS)
	$(CC) $(LIBDIR) -o $@ $^ $(LNFLAGS)

# pull in dependency info for existing .o files
-include $(OBJECTS:.o=.d)

# compile and generate dependency info
%.o: %.cc
	$(CC) -c $(CCFLAGS) $< -o $@
	$(CC) -M $(CCFLAGS) $*.cc > $*.d

.PHONY: clean
# clean out the directory but keep executables with command "clean"
clean : 
	rm -f *~ *.o *.d main




