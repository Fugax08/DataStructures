#pragma once
#include <stddef.h> // required for NULL
#include <stdint.h>

#define HEAD list_node_t **
#define ITEM  list_node_t *

struct list_node
{
    struct list_node *next;
};
typedef struct list_node list_node_t;

struct string_item
{
    list_node_t node;
    const char *string;
};
typedef struct string_item string_item_t;

list_node_t *list_get_tail(list_node_t **head);
list_node_t *list_append(list_node_t **head, list_node_t *item);
list_node_t *list_pop(list_node_t **head);

void PrintLinkedList(string_item_t *string_item);
string_item_t *string_item_new(const char *string);

list_node_t  *list_remove(list_node_t **head,list_node_t *item);
list_node_t  *list_reverse(list_node_t **head);