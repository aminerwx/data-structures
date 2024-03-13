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

int is_empty_pq(PriorityQueue *pq) { return pq->length ? 0 : 1; }

int priority_cmp(const void *a, const void *b) {
  return (((UserPQ *)b)->priority - ((UserPQ *)a)->priority);
}

int enqueuePQ(PriorityQueue *pq, UserPQ user) {
  if (pq->length == pq->capacity) {
    return 1;
  }
  pq->items[pq->length++] = user;
  if (pq->length >= 1) {
    qsort((void *)pq->items, pq->length, sizeof(UserPQ), priority_cmp);
  }
  printf("=> Enqueued User{ %s, %s, %lu }\n", user.username, user.password,
         user.priority);
  return 0;
}

UserPQ dequeuePQ(PriorityQueue *pq) {
  if (is_empty_pq(pq)) {
    printf("Queue is empty, nothing to dequeue.\n");
    return (UserPQ){0};
  }

  UserPQ head = pq->items[0];
  for (size_t i = 0; i < pq->length - 1; i++) {
    pq->items[i] = pq->items[i + 1];
  }
  pq->items[--(pq->length)] = (UserPQ){0};
  return head;
}

void init_pq(PriorityQueue *pq, size_t capacity) {
  pq->length = 0;
  pq->capacity = capacity;
  pq->items = calloc(capacity, sizeof(UserPQ));
}

void free_pq(PriorityQueue *pq) { free(pq->items); }

void printPriority(PriorityQueue *pq) {
  printf("\n");
  for (size_t i = 0; i < pq->length; i++) {
    printf("[%lu] %s %s %lu\n", i, pq->items[i].username, pq->items[i].password,
           pq->items[i].priority);
  }
  printf("\n=> Priority Queue: len = %lu, cap = %lu\n", pq->length,
         pq->capacity);
}

void priorityQueue_runner(void) {
  printf("\n\t\t[#]  Priority Queue  [#]\n");
  PriorityQueue pq = {0};
  size_t capacity = 5;
  init_pq(&pq, capacity);

  UserPQ user1 = {"user1", "pwd1", 10};
  UserPQ user2 = {"user2", "pwd2", 2};
  UserPQ user3 = {"user3", "pwd3", 99};
  UserPQ user4 = {"user4", "pwd4", 2};
  UserPQ user5 = {"user5", "pwd5", 47};
  enqueuePQ(&pq, user1);
  enqueuePQ(&pq, user2);
  enqueuePQ(&pq, user3);
  enqueuePQ(&pq, user4);
  enqueuePQ(&pq, user5);

  printPriority(&pq);

  dequeuePQ(&pq);
  dequeuePQ(&pq);
  dequeuePQ(&pq);
  printPriority(&pq);

  free_pq(&pq);
}
