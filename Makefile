APP_NAME=data-structures
CFLAGS= -Wall -Wextra -std=c2x -fsanitize=address -g
CC=gcc
BINARY=bin/$(APP_NAME)

all: queue.o stack.o hashtable.o  linkedlist.o main.o
	@mkdir -p bin
	@$(CC) $(CFLAGS) $(wildcard *.o) -o $(BINARY) 
	@rm -f *.o

queue.o: stack/stack.c
	@$(CC) $(CFLAGS) -c $(wildcard queue/*.c)

stack.o: stack/stack.c
	@$(CC) $(CFLAGS) -c $(wildcard stack/*.c)

hashtable.o: hashtable/hashtable.c
	@$(CC) $(CFLAGS) -c $(wildcard hashtable/*.c)

linkedlist.o: linkedlist/linkedlist.c
	@$(CC) $(CFLAGS) -c $(wildcard linkedlist/*.c)

main.o: main.c
#	@echo "Compiling main.o"
	@$(CC) $(CFLAGS) -c main.c

clean:
	@rm -f *.o ./$(BINARY)

run: clean all
	@./$(BINARY)

debug:
	@gdb ./$(BINARY)
