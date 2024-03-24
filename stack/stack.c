#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * returns:
 *     0: non-empty stack
 *     1: empty stack
 */
int is_empty_stack(Stack *stack) { return stack->length ? 0 : 1; }

// First-In: append to end of the stack
int push(Stack *stack, User user) {
  printf("Pushing User{ %s, %s } to the stack\n", user.username, user.password);
  if (stack->length == stack->capacity) {
    return 1;
  }
  stack->items[stack->length++] = user;
  return 0;
}

// First-Out: retrieve last item
User pop(Stack *stack) {
  if (is_empty_stack(stack)) {
    return (User){0};
  }
  User u = stack->items[stack->length - 1];
  stack->items[--(stack->length)] = (User){0};
  return u;
}

// FIFO Stack
void init_stack(Stack *stack, size_t capacity) {
  stack->length = 0;
  stack->capacity = capacity;
  stack->items = calloc(capacity, sizeof(User));
}

void free_stack(Stack *stack) { free(stack->items); };

void print_stack(Stack *stack) {
  printf("\n");
  for (size_t i = 0; i < stack->length; i++) {
    User u = stack->items[i];
    printf("[%lu] %s %s\n", i, u.username, u.password);
  }
  printf("\n=> Stack: len = %lu, cap = %lu\n", stack->length, stack->capacity);
}
