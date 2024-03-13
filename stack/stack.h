#include <stdlib.h>
#ifndef USER
#define USER
#include "../user/user.h"
#endif

typedef struct {
  size_t length;
  size_t capacity;
  User *items;
} Stack;

int is_empty_stack(Stack *stack);
int push(Stack *stack, User user);
User pop(Stack *stack);
void init_stack(Stack *stack, size_t capacity);
void free_stack(Stack *stack);
void print_stack(Stack *stack);
void stack_runner(void);
