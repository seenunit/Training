CC=g++

CFLAGS=-std=c++11 -Wall -O

SRCDIR   = src

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)

objects = $(SRCDIR)/algorithms.o

all : algorithms

algorithms :	$(objects)
	$(CC) $(CFLAGS) -o algorithms $(objects)

$(objects) :  $(SRCDIR)/elapsedtime.h

clean:
	rm algorithms $(objects)