typedef struct node {
  char *data;
  unsigned size;
  struct node *next;
} node_t;

node_t *ll_create(void);
void ll_print(node_t *head);
void ll_free(node_t *head);
void ll_insert_begin(node_t **head, char *data);
void ll_insert_end(node_t *head, char *data);
void ll_remove_end(node_t *head);
void ll_remove_begin(node_t **head);
