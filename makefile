CC=g++

CFLAGS=-std=c++11 -Wall -O

SRCDIR   = src

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)

OBJECTS = src/algorithms.o src/closestpairpoints.o

all: algorithms

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDES)
	$(CC) -c -o $@ $< $(CFLAGS) 

algorithms :	$(OBJECTS)
	$(CC) -o algorithms $(OBJECTS) $(CFLAGS)

clean:
	rm algorithms $(OBJECTS)
