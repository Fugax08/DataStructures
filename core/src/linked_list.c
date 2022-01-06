#include <stddef.h> // required for NULL
#include "linked_list.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


list_node_t *list_get_tail(list_node_t **head)
{
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;

    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }

    return last_node;
}


list_node_t *list_append(list_node_t **head, list_node_t *item)
{
    list_node_t *tail = list_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->next = NULL;

    return item;
}

list_node_t *list_pop(list_node_t **head)
{
    list_node_t *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }
    *head = (*head)->next;
    current_head->next = NULL;

    return current_head;
}

string_item_t *string_item_new(const char *string)
{
    string_item_t *item = malloc(sizeof(string_item_t));
    if (!item)
    {
        return NULL;
    }
    item->string = string;
    return item;
}

void print_linked_list(string_item_t *string_item)
{
    while(string_item)
    {
        printf("%s\n",string_item->string);
        string_item = (string_item_t *)string_item->node.next;
    }
}

list_node_t *list_remove(list_node_t **head,list_node_t *item)
{
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;

    while (current_node)
    {
        if(current_node->next == item)
        {
            current_node->next = item->next;
            item->next = NULL;
        }
        last_node = current_node;
        current_node = current_node->next;
    }

    return last_node;
}

list_node_t  *list_reverse(list_node_t **head)
{
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;
    list_node_t *last_last_node = NULL;

    while (current_node)
    {
        if(current_node != *head)
        {
            last_node->next = last_last_node;
        }
        last_last_node = last_node;
        last_node = current_node;
        current_node = current_node->next;
    }
    
    last_node->next = last_last_node;
    return last_node;
}
