#ifndef USER
#define USER
#include "user.h"
#endif

typedef struct {
  int size;
  UserPQ p_users[5];
} PriorityQueue;

PriorityQueue newPriorityQueue(void);
void printPriority(PriorityQueue *pq);
int enqueuePQ(PriorityQueue *pq, UserPQ user);
UserPQ dequeuePQ(PriorityQueue *pq);
int comparator(const void *a, const void *b);
