#include <stdlib.h>
#ifndef USER
#define USER
typedef struct {
  char *username;
  char *password;
} User;
#endif

typedef struct {
  size_t length;
  size_t capacity;
  User *items;
} Stack;

int is_empty(Stack *stack);
int init(Stack *stack, size_t capacity);
int push(Stack *stack, User user);
User pop(Stack *stack);
void print_stack(Stack *stack);
