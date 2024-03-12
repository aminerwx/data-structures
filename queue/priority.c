#include "priority.h"
#include <stdio.h>
#include <stdlib.h>

// This is a naive implementation
// priority is based on a sorted array where:
//  enqueue: O(N)
//  dequeue: O(1)

//  TODO: Heap-based implementation
//  enqueue: O(logN)
//  dequeue: O(logN)

int comparator(const void *a, const void *b) {
  UserPQ *user_a = (UserPQ *)a;
  UserPQ *user_b = (UserPQ *)b;
  return (user_b->priority - user_a->priority);
}

void printPriority(PriorityQueue *pq) {
  for (int i = 0; i < 5; i++) {
    printf("[%d] %s %s %d\n", i, pq->p_users[i].username,
           pq->p_users[i].password, pq->p_users[i].priority);
  }
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

UserPQ dequeuePQ(PriorityQueue *pq) {
  if (!pq->size) {
    UserPQ u = {0};
    return u;
  }
  UserPQ u = pq->p_users[0];
  UserPQ empty = {0};
  for (int i = 0; i < 4; i++) {
    pq->p_users[i] = pq->p_users[i + 1];
  }
  pq->p_users[4] = empty;
  pq->size--;
  return u;
}

PriorityQueue newPriorityQueue(void) {
  PriorityQueue pq = {0};
  pq.size = 0;
  return pq;
}

void priorityQueue(void) {
  PriorityQueue pq = newPriorityQueue();
  UserPQ user1 = {"user1", "pwd1", 10};
  UserPQ user2 = {"user2", "pwd2", 2};
  UserPQ user3 = {"user3", "pwd3", 99};
  UserPQ user4 = {"user4", "pwd4", 2};
  UserPQ user5 = {"user5", "pwd5", 47};

  printf("enqueuePQ\n");
  enqueuePQ(&pq, user1);
  enqueuePQ(&pq, user2);
  enqueuePQ(&pq, user3);
  enqueuePQ(&pq, user4);
  enqueuePQ(&pq, user5);
  printPriority(&pq);
  dequeuePQ(&pq);
  printf("dequeuePQ\n");
  printPriority(&pq);
}
