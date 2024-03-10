#include "priority.h"
#include <stdlib.h>

PriorityQueue newPriorityQueue(void) {
  PriorityQueue pq = {0};
  pq.size = 0;
  return pq;
}

int comparator(const void *a, const void *b) {
  UserPQ *user_a = (UserPQ *)a;
  UserPQ *user_b = (UserPQ *)b;
  return (user_b->priority - user_a->priority);
}

int enqueuePQ(PriorityQueue *pq, UserPQ user) {
  if (pq->size > 5) {
    return 1;
  }
  pq->p_users[pq->size++] = user;
  if (pq->size > 1) {
    qsort(pq->p_users, sizeof(pq->p_users) / sizeof(UserPQ), sizeof(UserPQ),
          comparator);
  }
  return 0;
}
