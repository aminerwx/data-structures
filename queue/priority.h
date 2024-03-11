#ifndef USER
#define USER
#include "user.h"
#endif

typedef struct {
  int size;
  UserPQ p_users[5];
} PriorityQueue;

void printPriority(PriorityQueue *pq);
int comparator(const void *a, const void *b);
int enqueuePQ(PriorityQueue *pq, UserPQ user);
UserPQ dequeuePQ(PriorityQueue *pq);
PriorityQueue newPriorityQueue(void);
