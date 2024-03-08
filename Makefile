APP_NAME=data-structures
CFLAGS= -Wall -Wextra -std=c2x -g
QUEUE_MODULE=queue
USER_MODULE=user
MODULE:=myqueue
CC=gcc

all: queue.o main.o
	@$(CC) $(CFLAGS) $(wildcard *.o) -o $(APP_NAME)
	@rm -f *.o

queue.o: $(QUEUE_MODULE)/$(QUEUE_MODULE).c
#	@echo "Compiling queue.o"
	@$(CC) $(CFLAGS) -c $(addprefix $(QUEUE_MODULE)/, $(QUEUE_MODULE).c)
#	@echo $(addprefix $(QUEUE_MODULE)/, $(QUEUE_MODULE).*)

main.o: main.c
#	@echo "Compiling main.o"
	@$(CC) $(CFLAGS) -c main.c

clean:
	@rm -f *.o $(APP_NAME)

run: clean all
	@./$(APP_NAME)
