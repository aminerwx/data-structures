#include "./linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

node_t *ll_create(void) { return (node_t *)calloc(1, sizeof(node_t)); }

void ll_print(node_t *head) {
  int i = 0;
  node_t *current = head;
  while (current != NULL) {
    printf("[%d] Data: %s\n", i++, current->data);
    current = current->next;
  }
}

void ll_free(node_t *head) {
  node_t *tmp;
  while (head != NULL) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

void ll_insert_begin(node_t **head, char *data) {
  node_t *new = ll_create();
  new->data = data;
  new->next = *head;
  *head = new;
}

void ll_insert_end(node_t *head, char *data) {
  if (head->data == NULL) {
    head->data = data;
  } else {
    node_t *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = (node_t *)malloc(sizeof(node_t));
    if (current == NULL) {
      return;
    }
    current->next->data = data;
    current->next->next = NULL;
  }
}
