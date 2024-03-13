APP_NAME=data-structures
CFLAGS= -Wall -Wextra -std=c2x -fsanitize=address -g
QUEUE_MODULE=queue
CC=gcc
BINARY=bin/$(APP_NAME)

all: queue.o stack.o main.o
	@mkdir -p bin
	@$(CC) $(CFLAGS) $(wildcard *.o) -o $(BINARY) 
	@rm -f *.o

queue.o: stack/stack.c
	@$(CC) $(CFLAGS) -c $(wildcard queue/*.c)

stack.o: stack/stack.c
	@$(CC) $(CFLAGS) -c $(wildcard stack/*.c)

main.o: main.c
#	@echo "Compiling main.o"
	@$(CC) $(CFLAGS) -c main.c

clean:
	@rm -f *.o ./$(BINARY)

run: clean all
	@./$(BINARY)

debug:
	@gdb ./$(BINARY)
