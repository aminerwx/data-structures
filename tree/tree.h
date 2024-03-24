
struct tree_node {
  char *value;
  struct tree_node *left;
  struct tree_node *right;
};

struct tree_node tree_create(char *node);
