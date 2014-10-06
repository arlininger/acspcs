CC = g++

all: squares

squares: square.o main.o
	$(CC) -v -g -o $@ $?

.PHONY: clean
clean:
	rm -f squares; rm -f *.o
