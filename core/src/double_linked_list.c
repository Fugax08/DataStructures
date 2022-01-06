#include <stddef.h> // required for NULL
#include "double_linked_list.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

double_list_node_t *double_list_get_tail(double_list_node_t **head)
{
    double_list_node_t *current_node = *head;
    double_list_node_t *last_node = NULL;

    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }

    return last_node;
}

double_list_node_t *double_list_append (double_list_node_t **head, double_list_node_t *item)
{
    double_list_node_t *tail = double_list_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;

    return item;
}

double_list_item_t *double_list_item_new(int n)
{
    double_list_item_t *item = malloc(sizeof(double_list_item_t));
    if (!item)
    {
        return NULL;
    }
    item->value = n;
    return item;
}

void print_double_linked_list(double_list_item_t *head)
{
    double_list_item_t *item = head;
    while(item)
    {
        printf("%d\n",item->value);
        item = (double_list_item_t *)item->node.next;
    }
}

double_list_node_t *double_list_remove (double_list_node_t **head, double_list_node_t *item)
{
    if (!item->prev)
    {
        double_list_node_t *new_head = item->next;
        *head = new_head;
        new_head->prev = NULL;
        item->next = NULL;

        return new_head;
    }
    double_list_node_t *node_next = item->next;
    double_list_node_t *node_prev = item->prev;
    node_prev->next = node_next;
    if(node_next)node_next->prev = node_prev;
    item->next=NULL;
    item->prev=NULL;

    return item;
}

double_list_node_t *double_list_insert_after(double_list_node_t **head, double_list_node_t *item_to_insert, double_list_node_t *item)
{
    if (!item->next)
    {
        double_list_append(head, item_to_insert);
        return item_to_insert;
    }
    double_list_node_t *node_next = item->next;
    
    item_to_insert->prev = item;
    item_to_insert->next = node_next;
    node_next->prev = item_to_insert;
    item->next = item_to_insert;

    return item;
}

double_list_node_t *double_list_insert_before(double_list_node_t **head, double_list_node_t *item_to_insert, double_list_node_t *item)
{
    if (!item->prev)
    {
        *head = item_to_insert;
        item_to_insert->prev = NULL;
    }
    else
    {
        double_list_node_t *node_prev = item->prev;
        
        item_to_insert->prev = node_prev;
        node_prev->next = item_to_insert;
    }
    item_to_insert->next = item;
    item->prev = item_to_insert;

    return item;
}
