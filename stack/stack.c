#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * returns:
 *     0: non-empty stack
 *     1: empty stack
 */
int is_empty(Stack *user_stack) { return user_stack->length ? 0 : 1; }

// FIFO Stack
int init(Stack *user_stack, size_t capacity) {
  *user_stack = (Stack){.capacity = capacity,
                        .length = 0,
                        .items = calloc(capacity, sizeof(User))};
  return 0;
}

// First-In: append to end of the stack
int push(Stack *user_stack, User user) {
  printf("Pushing User{ %s, %s } to the stack\n", user.username, user.password);
  if (user_stack->length == user_stack->capacity) {
    return 1;
  }
  user_stack->items[user_stack->length++] = user;
  return 0;
}

void print_stack(Stack *stack) {
  for (size_t i = 0; i < stack->capacity; i++) {
    User u = stack->items[i];
    printf("[%lu] %s %s\n", i, u.username, u.password);
  }
  printf("len = %lu, cap = %lu\n", stack->length, stack->capacity);
}

// First-Out: retrieve last item
User pop(Stack *stack) {
  if (is_empty(stack)) {
    return (User){0};
  }
  User u = stack->items[stack->length - 1];
  stack->items[stack->length-- - 1] = (User){0};
  return u;
}
