#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void init_queue(Queue *queue, size_t capacity) {
  queue->length = 0;
  queue->capacity = capacity;
  queue->items = calloc(capacity, sizeof(User));
}
void free_queue(Queue *queue) { free(queue->items); }

int is_empty_queue(Queue *queue) { return queue->length ? 0 : 1; }

int enqueue(Queue *queue, User user) {
  if (queue->length == queue->capacity) {
    printf("Enqueue error: queue capacity reached.\n");
    return 1;
  }
  queue->items[queue->length++] = user;
  printf("=> Enqueued User{ %s, %s }\n", user.username, user.password);
  return 0;
}

User dequeue(Queue *queue) {
  if (is_empty_queue(queue)) {
    printf("Queue is empty, nothing to dequeue.\n");
    return (User){0};
  }
  User head = queue->items[0];
  for (size_t i = 0; i < queue->length - 1; i++) {
    queue->items[i] = queue->items[i + 1];
  }
  queue->items[--(queue->length)] = (User){0};
  return head;
}

void printQueue(Queue *queue) {
  printf("\n");
  for (size_t i = 0; i < queue->length; i++) {
    printf("[%lu] %s %s\n", i, queue->items[i].username,
           queue->items[i].password);
  }
  printf("\n=> Queue: len = %lu, cap = %lu\n", queue->length, queue->capacity);
}

void queue_runner(void) {
  printf("\n\t\t[#]  Queue  [#]\n");
  Queue users_queue = {0};
  init_queue(&users_queue, 5);

  User user1 = {"user1", "pwd1"};
  User user2 = {"user2", "pwd2"};
  User user3 = {"user3", "pwd3"};
  enqueue(&users_queue, user1);
  enqueue(&users_queue, user2);
  enqueue(&users_queue, user3);

  printQueue(&users_queue);

  User dequeued_user = dequeue(&users_queue);
  printf("\n=> Dequeued User{ %s, %s }\n\n", dequeued_user.username,
         dequeued_user.password);

  printQueue(&users_queue);

  User peeked_user = peek(&users_queue);
  printf("\n=> Peeked User{ %s, %s }\n\n", peeked_user.username,
         peeked_user.password);
  free_queue(&users_queue);
}

User peek(Queue *queue) { return queue->length ? queue->items[0] : (User){0}; }
