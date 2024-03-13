#include <stdlib.h>

typedef struct {
  char *username;
  char *password;
} User;

typedef struct {
  char *username;
  char *password;
  size_t priority;
} UserPQ;
