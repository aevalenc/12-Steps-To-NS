# Author: Alejandro Valencia
# Project: Makefile for 12 Steps to NS
# Update: November 20, 2021

# Choose Compiler
GPP = gcc

# Flags
CPP_FLAGS = -c -fpic -Wall

# Include Libraries
CPP_INC =

# Linking Libraries
CPP_LIBS = -lm

# Name of source and object files
# Change the following to compile the desired step
srcfile = Step1.c
objects = Step1.o

# Name of executable
EXEC = main

# Recipes
$(EXEC) : $(objects) $(srcfile)
	$(GPP)  $(objects) -o $(EXEC) $(CPP_LIBS)

$(objects) : $(srcfile)
	$(GPP) $(CPP_FLAGS) $(srcfile)


# Cleanup
clean :
	rm *.o main
