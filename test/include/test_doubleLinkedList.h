#include "clove.h"
#include "double_linked_list.h"
#include <stdio.h>


CLOVE_TEST(DoubleLinkedList_append)
{
    double_list_item_t *double_linked_list = NULL;
    double_list_item_t *first = double_list_item_new(1);
    double_list_item_t *second = double_list_item_new(2);
    double_list_item_t *third = double_list_item_new(3);
    double_list_item_t *fourth = double_list_item_new(4);

    double_list_append((DHEAD)&double_linked_list, (DITEM)first);
    double_list_append((DHEAD)&double_linked_list, (DITEM)second);
    double_list_append((DHEAD)&double_linked_list, (DITEM)third);

    //print_double_linked_list(double_linked_list);

    CLOVE_PTR_EQ(double_linked_list, first);
    CLOVE_PTR_EQ(first->node.next, second);
    CLOVE_PTR_EQ(first->node.prev, NULL); 
    CLOVE_PTR_EQ(second->node.next, third);
    CLOVE_PTR_EQ(second->node.prev, first); 
    CLOVE_PTR_NE(third->node.next, fourth);
    CLOVE_PTR_EQ(third->node.prev, second);
}

CLOVE_TEST(DoubleLinkedList_remove)
{
    double_list_item_t *double_linked_list = NULL;
    double_list_item_t *first = double_list_item_new(1);
    double_list_item_t *second = double_list_item_new(2);
    double_list_item_t *third = double_list_item_new(3);
    double_list_item_t *fourth = double_list_item_new(4);

    double_list_append((DHEAD)&double_linked_list, (DITEM)first);
    double_list_append((DHEAD)&double_linked_list, (DITEM)second);
    double_list_append((DHEAD)&double_linked_list, (DITEM)third);

    //print_double_linked_list(double_linked_list);

    double_list_remove((DHEAD)&double_linked_list, (DITEM)second);
    
    //print_double_linked_list(double_linked_list);

    CLOVE_PTR_EQ(double_linked_list, first);
    CLOVE_PTR_NE(first->node.next, second); 
    CLOVE_PTR_EQ(first->node.next, third); 
    CLOVE_PTR_NE(second->node.next, third); 
    CLOVE_PTR_EQ(second->node.next, NULL); 
    CLOVE_PTR_NE(third->node.next, fourth);
    CLOVE_PTR_EQ(third->node.prev, first);
}

CLOVE_TEST(DoubleLinkedList_removeFirstItemAndLastItem)
{
    double_list_item_t *double_linked_list = NULL;
    double_list_item_t *first = double_list_item_new(1);
    double_list_item_t *second = double_list_item_new(2);
    double_list_item_t *third = double_list_item_new(3);
    double_list_item_t *fourth = double_list_item_new(4);

    double_list_append((DHEAD)&double_linked_list, (DITEM)first);
    double_list_append((DHEAD)&double_linked_list, (DITEM)second);
    double_list_append((DHEAD)&double_linked_list, (DITEM)third);
    double_list_append((DHEAD)&double_linked_list, (DITEM)fourth);

    //print_double_linked_list(double_linked_list);

    double_list_remove((DHEAD)&double_linked_list, (DITEM)first);
    
    //print_double_linked_list(double_linked_list);

    CLOVE_PTR_EQ(double_linked_list, second);
    CLOVE_PTR_EQ(first->node.next, NULL); 
    CLOVE_PTR_EQ(second->node.next, third); 
    CLOVE_PTR_EQ(second->node.prev, NULL); 
    CLOVE_PTR_EQ(third->node.next, fourth);
    CLOVE_PTR_EQ(third->node.prev, second);
    CLOVE_PTR_EQ(fourth->node.next, NULL);
    CLOVE_PTR_EQ(fourth->node.prev, third);

    //print_double_linked_list(double_linked_list);

    double_list_remove((DHEAD)&double_linked_list, (DITEM)fourth);
    
    //print_double_linked_list(double_linked_list);

    CLOVE_PTR_EQ(double_linked_list, second);
    CLOVE_PTR_EQ(first->node.next, NULL); 
    CLOVE_PTR_EQ(second->node.next, third); 
    CLOVE_PTR_EQ(second->node.prev, NULL); 
    CLOVE_PTR_EQ(third->node.next, NULL);
    CLOVE_PTR_EQ(third->node.prev, second);
    CLOVE_PTR_EQ(fourth->node.next, NULL);
    CLOVE_PTR_EQ(fourth->node.prev, NULL);
}

CLOVE_TEST(DoubleLinkedList_itemInsertAfterAndAfterTail)
{
    double_list_item_t *double_linked_list = NULL;
    double_list_item_t *first = double_list_item_new(1);
    double_list_item_t *second = double_list_item_new(2);
    double_list_item_t *third = double_list_item_new(3);
    double_list_item_t *fourth = double_list_item_new(4);

    double_list_append((DHEAD)&double_linked_list, (DITEM)first);
    double_list_append((DHEAD)&double_linked_list, (DITEM)third);

    //print_double_linked_list(double_linked_list);

    double_list_insert_after((DHEAD)&double_linked_list, (DITEM)second, (DITEM)first);
    
    //print_double_linked_list(double_linked_list);
    
    double_list_insert_after((DHEAD)&double_linked_list, (DITEM)fourth, (DITEM)third);

    //print_double_linked_list(double_linked_list);

    CLOVE_PTR_EQ(double_linked_list, first);
    CLOVE_PTR_EQ(first->node.next, second); 
    CLOVE_PTR_EQ(first->node.prev, NULL); 
    CLOVE_PTR_EQ(second->node.next, third); 
    CLOVE_PTR_EQ(second->node.prev, first); 
    CLOVE_PTR_EQ(third->node.next, fourth);
    CLOVE_PTR_EQ(third->node.prev, second);
    CLOVE_PTR_EQ(fourth->node.next, NULL);
    CLOVE_PTR_EQ(fourth->node.prev, third);
}

CLOVE_TEST(DoubleLinkedList_itemInsertBefore)
{
    double_list_item_t *double_linked_list = NULL;
    double_list_item_t *first = double_list_item_new(1);
    double_list_item_t *second = double_list_item_new(2);
    double_list_item_t *third = double_list_item_new(3);
    double_list_item_t *fourth = double_list_item_new(4);

    double_list_append((DHEAD)&double_linked_list, (DITEM)first);
    double_list_append((DHEAD)&double_linked_list, (DITEM)second);
    double_list_append((DHEAD)&double_linked_list, (DITEM)third);

    //print_double_linked_list(double_linked_list);

    double_list_insert_before((DHEAD)&double_linked_list, (DITEM)fourth, (DITEM)second);
    
    //print_double_linked_list(double_linked_list);

    CLOVE_PTR_EQ(double_linked_list, first);
    CLOVE_PTR_EQ(first->node.next, fourth); 
    CLOVE_PTR_EQ(second->node.next, third); 
    CLOVE_PTR_EQ(second->node.prev, fourth); 
    CLOVE_PTR_EQ(third->node.next, NULL);
    CLOVE_PTR_EQ(third->node.prev, second);
    CLOVE_PTR_EQ(fourth->node.next, second);
    CLOVE_PTR_EQ(fourth->node.prev, first);
}

CLOVE_TEST(DoubleLinkedList_itemInsertBeforeHead)
{
    double_list_item_t *double_linked_list = NULL;
    double_list_item_t *first = double_list_item_new(1);
    double_list_item_t *second = double_list_item_new(2);
    double_list_item_t *third = double_list_item_new(3);
    double_list_item_t *fourth = double_list_item_new(4);

    double_list_append((DHEAD)&double_linked_list, (DITEM)first);
    double_list_append((DHEAD)&double_linked_list, (DITEM)second);
    double_list_append((DHEAD)&double_linked_list, (DITEM)third);

    //print_double_linked_list(double_linked_list);

    double_list_insert_before((DHEAD)&double_linked_list, (DITEM)fourth, (DITEM)first);
    
    //print_double_linked_list(double_linked_list);

    CLOVE_PTR_EQ(double_linked_list, fourth);
    CLOVE_PTR_EQ(first->node.next, second); 
    CLOVE_PTR_EQ(first->node.prev, fourth); 
    CLOVE_PTR_EQ(second->node.next, third); 
    CLOVE_PTR_EQ(second->node.prev, first); 
    CLOVE_PTR_EQ(third->node.next, NULL);
    CLOVE_PTR_EQ(third->node.prev, second);
    CLOVE_PTR_EQ(fourth->node.next, first);
    CLOVE_PTR_EQ(fourth->node.prev, NULL);
}

CLOVE_TEST(DoubleLinkedList_shuffle)
{
    double_list_item_t *double_linked_list = NULL;
    double_list_item_t *first = double_list_item_new(1);
    double_list_item_t *second = double_list_item_new(2);
    double_list_item_t *third = double_list_item_new(3);
    double_list_item_t *fourth = double_list_item_new(4);

    double_list_append((DHEAD)&double_linked_list, (DITEM)first);
    double_list_append((DHEAD)&double_linked_list, (DITEM)second);
    double_list_append((DHEAD)&double_linked_list, (DITEM)third);
    double_list_append((DHEAD)&double_linked_list, (DITEM)fourth);

    print_double_linked_list(double_linked_list);

    double_list_shuffle((DHEAD)&double_linked_list);
    
    print_double_linked_list(double_linked_list);

    CLOVE_PTR_NE(double_linked_list, first);
}

