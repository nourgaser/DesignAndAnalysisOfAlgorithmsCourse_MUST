CC=g++
CFLAGS=-I.
DEPS = utils.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o utils.o 
	$(CC) -o solution main.o utils.o 
