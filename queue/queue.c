#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue newQueue(void) {
  Queue q;
  q.size = 0;
  for (int i = 0; i < 10; i++) {
    q.users[i] = NULL;
  }
  return q;
}

int enqueue(Queue *queue, User *user) {
  if (queue->size < 10) {
    int i = queue->size;
    queue->users[i] = user;
    //    queue->users[i] = user->password;
    queue->size++;
    printf("Enqueued User{ %s, %s }\n", user->username, user->password);
    return 0;
  }
  return 1;
}

User *dequeue(Queue *queue) {
  if (queue->size > 0 && queue->size < 10) {
    User *user = queue->users[0];
    for (int i = 0; i < queue->size + 1; i++) {
      queue->users[i] = queue->users[i + 1];
    }
    queue->size--;
    return user;
  }
  return NULL;
}

void printQueue(Queue q) {
  printf("Queue[%d] = {\n", q.size);
  for (int i = 0; i < q.size; i++) {
    printf("\tUser[%d]: %s, %s\n", i, q.users[i]->username,
           q.users[i]->password);
  }
  printf("}\n");
}

void queue(void) {
  Queue q = newQueue();
  User user = {"aminerwx", "123123"};
  int status = enqueue(&q, &user);
  if (status == 0) {
    printQueue(q);
  }

  User *dq = dequeue(&q);
  printf("Dequeued User{ %s, %s }\n", dq->username, dq->password);
  printQueue(q);
}

User *peek(Queue *queue) { return queue->size == 0 ? NULL : queue->users[0]; }
