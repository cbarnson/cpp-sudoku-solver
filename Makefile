# Makefile for sudoku problem
# Cody Barnson
# wed Mar 23

# uses gnu c++ compiler program
CCC = g++11

# list all warnings
CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11

# all is the target, after the colon is the dependencies
# "the target all is dependent on the executables"
all : main

# the target <executable> is dependent on the list of dependencies
main : main.o
	$(CCC) $(CCCFLAGS) -o $@ $^

# the default compiling rule for .cc to .o
%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

# clean commands
# clean out the directory but keep executables with command "clean"
clean : 
	rm -f *.o *~ *% *# .#*

# clean out the directory including the executables
clean-all : clean
	rm -f main





