#CC = g++

all: squares

CFLAGS = -g
CXXFLAGS = -g

squares: square.o main.o gcd.o
	$(CXX) -g -o $@ $?

.PHONY: clean
clean:
	rm -f squares; rm -f *.o
