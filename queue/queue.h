#ifndef USER
#define USER
#include "../user/user.h"
#endif

typedef struct {
  size_t length;
  size_t capacity;
  User *items;
} Queue;

void queue_runner(void);
void printQueue(Queue *queue);
int is_empty_queue(Queue *queue);
int enqueue(Queue *queue, User user);
User dequeue(Queue *queue);
User peek(Queue *queue);
void init_queue(Queue *queue, size_t capacity);
void free_queue(Queue *queue);
