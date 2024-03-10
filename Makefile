APP_NAME=data-structures
CFLAGS= -Wall -Wextra -std=c2x -g
QUEUE_MODULE=queue
CC=gcc
BINARY=bin/$(APP_NAME)

all: queue.o main.o
	@mkdir -p bin
	@$(CC) $(CFLAGS) $(wildcard *.o) -o $(BINARY) 
	@rm -f *.o

queue.o: $(QUEUE_MODULE)/$(QUEUE_MODULE).c
#	@echo "Compiling queue.o"
	@$(CC) $(CFLAGS) -c $(wildcard queue/*.c)
#	@echo $(addprefix $(QUEUE_MODULE)/, $(QUEUE_MODULE).*)

main.o: main.c
#	@echo "Compiling main.o"
	@$(CC) $(CFLAGS) -c main.c

clean:
	@rm -f *.o ./$(BINARY)

run: clean all
	@./$(BINARY)
