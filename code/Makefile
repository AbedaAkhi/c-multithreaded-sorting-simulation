CC = gcc
CFLAGS = -Wall -pthread
OBJ = main.o thread.o
EXEC = sss

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(CFLAGS)

main.o: main.c thread.h
	$(CC) -c main.c $(CFLAGS)

thread.o: thread.c thread.h
	$(CC) -c thread.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)

.PHONY: clean
