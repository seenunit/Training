CC=g++

CFLAGS=-g -std=c++11 -Wall -O

SRCDIR = src
OBJDIR = obj

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)

OBJECTS = $(OBJDIR)/algorithms.o  $(OBJDIR)/closestpairpoints.o $(OBJDIR)/quicksort.o \
	  $(OBJDIR)/countinginversions.o

all: algorithms

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDES)
	$(CC) -c -o $@ $< $(CFLAGS) 

algorithms :	$(OBJECTS)
	$(CC) -o algorithms $(OBJECTS) $(CFLAGS)

clean:
	rm algorithms $(OBJECTS)
