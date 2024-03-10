#include "queue/priority.h"
#include "queue/queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // queue();
  PriorityQueue pq = newPriorityQueue();
  UserPQ user1 = {"a", "1", 10};
  UserPQ user2 = {"b", "2", 2};
  UserPQ user3 = {"c", "3", 99};
  UserPQ user4 = {"d", "4", 2};
  UserPQ user5 = {"e", "5", 47};

  enqueuePQ(&pq, user1);
  enqueuePQ(&pq, user2);
  enqueuePQ(&pq, user3);
  enqueuePQ(&pq, user4);
  enqueuePQ(&pq, user5);

  for (int i = 0; i < 5; i++) {
    printf("%s %s %d\n", pq.p_users[i].username, pq.p_users[i].password,
           pq.p_users[i].priority);
  }
  return EXIT_SUCCESS;
}
