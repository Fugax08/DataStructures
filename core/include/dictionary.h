#pragma once
#include <stddef.h> // required for NULL
#include <stdint.h>

typedef struct dictionary_node
{
    const char *key;
    size_t key_len;
    const char *value;
    struct dictionary_node *next;
    struct dictionary_node *prev;
}dictionary_node_t;

typedef struct dictionary_table
{
    struct dictionary_node **nodes;
    size_t hashmap_size ;
}dictionary_table_t;

size_t djb33x_hash(const char *key, const size_t keylen);

dictionary_table_t *dictionary_table_new (const size_t hashmap_size );

dictionary_node_t *dictionary_insert(dictionary_table_t *table, const char *key, const size_t key_len, const char *value);
dictionary_node_t *dictionary_search (dictionary_table_t *table, const char *key, const size_t key_len );
int dictionary_removal (dictionary_table_t *table, const char *key, const size_t key_len );