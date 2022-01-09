#include <stddef.h> // required for NULL
#include "sets.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

size_t djb33x_hash(const char *key, const size_t keylen)
{
    size_t hash = 5381;
    for (size_t i = 0; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }
    return hash;
}

set_table_t *set_table_new (const size_t hashmap_size )
{
    set_table_t *table = malloc(sizeof(set_table_t ));
    if (!table)
    {
        return NULL;
    }
    table->hashmap_size = hashmap_size ;
    table->nodes = calloc(table->hashmap_size , sizeof(set_node_t *));
    if (!table->nodes)
    {
        free(table);
        return NULL;
    }
    return table;
}

set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len)
{
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    set_node_t *head = table->nodes[index];
    if (!head)
    {
        table->nodes[index] = malloc(sizeof(set_node_t));
        if (!table->nodes[index])
        {
            return NULL;
        }
        table->nodes[index]->key = key;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->next = NULL;
        table->nodes[index]->prev = NULL;
        return table->nodes[index];
    }    
    set_node_t *new_item = malloc(sizeof(set_node_t));
    if (!new_item)
    {
        return NULL;
    }
    new_item->key = key;
    new_item->key_len = key_len;
    new_item->next = NULL;
    new_item->prev = NULL;
    set_node_t *tail = head;
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

set_node_t *set_search (set_table_t *table, const char *key, const size_t key_len )
{
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    set_node_t *head = table->nodes[index];
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

int set_removal (set_table_t *table, const char *key, const size_t key_len )
{
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    set_node_t *head = table->nodes[index];
    while (head)
    {
        if (head->key_len == key_len)
        {
            if (head->key == key)
            {
                if (head->prev)
                {
                    set_node_t *prev = NULL;
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
                head->next = NULL;
                head->prev = NULL;
                return 0;
            }
        }
        head = head->next;
    }
    return 1;
}