#include <stdlib.h>
typedef struct {
  char *username;
  char *password;
} User;

typedef struct {
  int size;
  User users[];
} PriorityQueue;

void printQueue(PriorityQueue *pq);
int enqueue(PriorityQueue *pq, User *user);
User dequeue(PriorityQueue *pq);
PriorityQueue newPriorityQueue();
