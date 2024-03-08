typedef struct {
  char *username;
  char *password;
} User;

typedef struct {
  int size;
  User *users[10];
} Queue;

void queue(void);
void printQueue(Queue q);
int enqueue(Queue *queue, User *user);
User *dequeue(Queue *queue);
User *peek(Queue *queue);
Queue newQueue(void);
