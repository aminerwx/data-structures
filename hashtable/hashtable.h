/*
 *
 * Hash function:
 *  -
 */
#include <stdlib.h>

typedef struct {
  const char *title;
} Book;

typedef struct {
  const char *key;
  Book *value;
} Item;

typedef struct {
  Item *items;
  size_t length;
  size_t capacity;
} HashTable;

unsigned ht_func(const char *str, unsigned length);
void ht_create(HashTable *ht, size_t capacity);
void ht_destroy(HashTable *ht);
void ht_put(HashTable *ht, Item book);
void ht_remove(HashTable *ht, Item book);
void ht_print(HashTable *ht);
float ht_load_factor(HashTable *ht);
Item ht_get(HashTable *ht, const char *key);
