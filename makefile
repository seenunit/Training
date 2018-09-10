CC=g++

CFLAGS=-std=c++11 -Wall -O3 -m64

SRCDIR   = src
MATGENDIR = matgensrc

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)


all: algorithms
	
algorithms:	
	$(CC) $(CFLAGS) $(SOURCES) $(INCLUDES) -o algorithms

clean:
	rm -f *.o algorithms