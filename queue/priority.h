#include <stdlib.h>
#ifndef USER
#define USER
#include "../user/user.h"
#endif

typedef struct {
  size_t length;
  size_t capacity;
  UserPQ *items;
} PriorityQueue;

int is_empty_pq(PriorityQueue *pq);
int priority_cmp(const void *a, const void *b);
int enqueuePQ(PriorityQueue *pq, UserPQ user);
UserPQ dequeuePQ(PriorityQueue *pq);
void init_pq(PriorityQueue *pq, size_t capacity);
void free_pq(PriorityQueue *pq);
void printPriority(PriorityQueue *pq);
