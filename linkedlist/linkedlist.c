#include "./linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

node_t *ll_create(void) { return (node_t *)calloc(1, sizeof(node_t)); }

void ll_print(node_t *head) {
  if (head == NULL) {
    return;
  }
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
    tmp = NULL;
  }
}

void ll_insert_begin(node_t **head, char *data) {
  node_t *new = ll_create();
  new->data = data;
  new->next = *head;
  new->size = (*head)->size + 1;
  *head = new;
}

void ll_insert_end(node_t *head, char *data) {
  if (head->data == NULL) {
    head->data = data;
    head->size++;
  } else {
    node_t *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = ll_create();
    if (current == NULL) {
      return;
    }
    current->next->data = data;
    head->size++;
  }
}

void ll_remove_end(node_t *head) {
  if (head->next == NULL) {
    head->data = NULL;
    head->size = 0;
    return;
  }
  node_t *current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
  head->size--;
}

void ll_remove_begin(node_t **head) {
  if ((*head)->next == NULL) {
    (*head)->data = NULL;
    (*head)->size = 0;
    return;
  }
  node_t *tmp = *head;
  *head = (*head)->next;
  (*head)->size = --tmp->size;
  free(tmp);
}
