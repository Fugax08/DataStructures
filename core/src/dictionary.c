#include <stddef.h> // required for NULL
#include "dictionary.h"
#include "sets.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

dictionary_table_t *dictionary_table_new (const size_t hashmap_size )
{
    dictionary_table_t *table = malloc(sizeof(dictionary_table_t ));
    if (!table)
    {
        return NULL;
    }
    table->hashmap_size = hashmap_size ;
    table->nodes = calloc(table->hashmap_size , sizeof(dictionary_node_t *));
    if (!table->nodes)
    {
        free(table);
        return NULL;
    }
    return table;
}

dictionary_node_t *dictionary_insert(dictionary_table_t *table, const char *key, const size_t key_len, const char *value)
{
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    dictionary_node_t *head = table->nodes[index];
    if (!head)
    {
        table->nodes[index] = malloc(sizeof(dictionary_node_t));
        if (!table->nodes[index])
        {
            return NULL;
        }
        table->nodes[index]->key = malloc(sizeof(char));
        strncpy(table->nodes[index]->key, key ,key_len);
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->value = value;
        table->nodes[index]->next = NULL;
        table->nodes[index]->prev = NULL;
        return table->nodes[index];
    }    
    dictionary_node_t *new_item = malloc(sizeof(dictionary_node_t));
    if (!new_item)
    {
        return NULL;
    }
    new_item->key = key;
    new_item->key_len = key_len;
    new_item->value = value;
    new_item->next = NULL;
    new_item->prev = NULL;
    dictionary_node_t *tail = head;
    while (head)
    {
        if (head->key_len == new_item->key_len)
        {
            if (head->key == new_item->key)
            {
                return head;
            }
        }
        
        tail = head;
        head = head->next;
    }
    tail->next = new_item;
    new_item->prev = tail;
    return new_item;
}

dictionary_node_t *dictionary_search (dictionary_table_t *table, const char *key, const size_t key_len )
{
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    dictionary_node_t *head = table->nodes[index];
    while (head)
    {
        if (head->key_len == key_len)
        {
            if (head->key == key)
            {
                return head;
            }
        }
        
        head = head->next;
    }

    return NULL;
}

int dictionary_removal (dictionary_table_t *table, const char *key, const size_t key_len )
{
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    dictionary_node_t *head = table->nodes[index];
    while (head)
    {
        if (head->key_len == key_len)
        {
            if (head->key == key)
            {
                if (head->prev)
                {
                    dictionary_node_t *prev = head->prev;
                    prev->next = NULL;
                    if (head->next)
                    {
                        prev->next = head->next;
                    }
                }
                else
                {
                    table->nodes[index] = NULL;
                    if (head->next)
                    {
                        table->nodes[index] = head->next;
                    }
                }
                head->key = NULL;
                head->key_len = 0;
                head->value = NULL;
                head->next = NULL;
                head->prev = NULL;
                return 0;
            }
        }
        head = head->next;
    }
    return 1;
}