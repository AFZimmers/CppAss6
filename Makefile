#Makefile for Assignment 6
#Alexander Zimmermann ZMMALE001

CC=g++
CCFLAGS=-std=c++11

SRC = $(wildcard src/*.cpp *.h)
OBJ = $(SRC:.cpp=.o)

PROG = value_iterator

$(PROG) : $(OBJ)
	$(CC) $(CCFLAGS) $(SRC) -o value_iterator
	
.cpp.o:
	$(CC) $(CCFLAGS) -c $<

depend:
	$(CC) -M $(SRC) > incl.defs

clean:
	rm -f *.o
	rm -f value_iterator
