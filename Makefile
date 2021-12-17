CC=g++
CFLAGS=-I.
DEPS = utils.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o utils.o 
	$(CC) -o solution main.o utils.o 