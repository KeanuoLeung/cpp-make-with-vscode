CC=g++
CFLAGS=-I. -std=c++11 -Wall -g
DEPS = msg.h
OBJ = main.o msg.o

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)