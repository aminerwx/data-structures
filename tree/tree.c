#include "tree.h"
#include <stdlib.h>

struct tree_node tree_create(char *value) {
  return (struct tree_node){.value = value, .left = NULL, .right = NULL};
}
