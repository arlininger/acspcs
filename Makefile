CC = g++

all: squares

squares: square.o main.o gcd.o
	$(CC) -g -o $@ $?

.PHONY: clean
clean:
	rm -f squares; rm -f *.o
