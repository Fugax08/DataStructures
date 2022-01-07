#pragma once

#define DHEAD double_list_node_t **
#define DITEM  double_list_node_t *

struct double_list_node
{
    struct double_list_node *prev;
    struct double_list_node *next;
};
typedef struct double_list_node double_list_node_t;

struct double_list_item
{
    double_list_node_t node;
    int value;
};
typedef struct double_list_item double_list_item_t;

double_list_node_t *double_list_append(double_list_node_t **head, double_list_node_t *item);
double_list_node_t *double_list_get_tail(double_list_node_t **head);

void print_double_linked_list(double_list_item_t *head);
double_list_item_t *double_list_item_new(int n);

double_list_node_t *double_list_remove (double_list_node_t **head, double_list_node_t *item);
double_list_node_t *double_list_insert_after (double_list_node_t **head, double_list_node_t *item_to_insert, double_list_node_t *item);
double_list_node_t *double_list_insert_before (double_list_node_t **head, double_list_node_t *item_to_insert, double_list_node_t *item);
void double_list_shuffle(double_list_node_t **head);