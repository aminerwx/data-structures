#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>

unsigned ht_func(const char *str, unsigned capacity) {
  int i = 0;
  unsigned hash = 0;

  while (str[i]) {
    hash += str[i++];
  }

  return hash % capacity;
}

void ht_create(HashTable *ht, size_t capacity) {
  ht->length = 0;
  ht->capacity = capacity;
  ht->items = calloc(capacity, sizeof(Item));
  printf("Hashtable: len = %lu, cap = %lu\n", ht->length, ht->capacity);
}

void ht_destroy(HashTable *ht) { free(ht->items); }

void ht_put(HashTable *ht, Item item) {
  if (ht->length == ht->capacity) {
    printf("Hashtable is full.\n");
    return;
  }
  unsigned item_hash = ht_func(item.key, ht->capacity);
  if (ht->items[item_hash].key) {
    printf("Collision @ index: %u\n", item_hash);
    // Handle Collision
    // Linear Probing
    while (ht->items[item_hash].key) {
      if (item_hash >= ht->capacity) {
        item_hash = 0;
      }
      item_hash++;
    }
    printf("Next available index: %u\n", item_hash);
  }
  ht->items[item_hash].key = item.key;
  ht->items[item_hash].value = item.value;
  ht->length++;
  printf("Added: [%u] { %s: %s }\n", item_hash, ht->items[item_hash].key,
         ht->items[item_hash].value->title);
}

void ht_remove(HashTable *ht, Item item) {
  if (!item.key) {
    printf("Argument item is empty.\n");
    return;
  }
  for (unsigned i = 0; i < ht->length; i++) {
    if (item.key == ht->items[i].key && item.value == ht->items[i].value) {
      printf("Removed: [%u] { %s: %s }\n", i, item.key, item.value->title);
      ht->items[i] = (Item){0};
      ht->length--;
    }
  }
}

Item ht_get(HashTable *ht, unsigned index) {
  return ht->items[index].key ? ht->items[index] : (Item){0};
}

void ht_print(HashTable *ht) {
  for (unsigned i = 0; i < ht->capacity; i++) {
    if (ht->items[i].value) {
      printf("[%u] { %s: (%p, %s) }\n", i, ht->items[i].key, ht->items[i].value,
             ht->items[i].value->title);
    } else {
      printf("[%u] { %s: %p }\n", i, ht->items[i].key, ht->items[i].value);
    }
  }
}
