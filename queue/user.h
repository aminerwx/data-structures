typedef struct {
  char *username;
  char *password;
} User;

typedef struct {
  char *username;
  char *password;
  unsigned int priority;
} UserPQ;
