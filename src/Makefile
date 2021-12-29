CC=g++
CFLAGS=-I.
DEPS = utils.h hungarian.h
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o utils.o hungarian.o
	$(CC) -o solution main.o hungarian.o utils.o

clean:
	rm *.o solution