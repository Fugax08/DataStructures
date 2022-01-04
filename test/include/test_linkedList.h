#include "clove.h"
#include "linked_list.h"


CLOVE_TEST(LinkedList_appendStringItemNew)
{
    string_item_t *linked_list = NULL;
    string_item_t *first = string_item_new("first");
    string_item_t *second = string_item_new("second");
    string_item_t *third = string_item_new("third");
    string_item_t *fourth = string_item_new("fourth");

    list_append((HEAD)&linked_list, (ITEM)first);
    list_append((HEAD)&linked_list, (ITEM)second);
    list_append((HEAD)&linked_list, (ITEM)third);

    //PrintLinkedList(linked_list);

    CLOVE_PTR_EQ(linked_list, first); 
    CLOVE_PTR_EQ(first->node.next, second); 
    CLOVE_PTR_EQ(second->node.next, third); 
    CLOVE_PTR_NE(third->node.next, fourth); 
}

CLOVE_TEST(LinkedList_pop)
{
    string_item_t *linked_list = NULL;
    string_item_t *first = string_item_new("first");
    string_item_t *second = string_item_new("second");
    string_item_t *third = string_item_new("third");
    string_item_t *fourth = string_item_new("fourth");

    list_append((HEAD)&linked_list, (ITEM)first);
    list_append((HEAD)&linked_list, (ITEM)second);
    list_append((HEAD)&linked_list, (ITEM)third);

    list_pop((HEAD)&linked_list);

    //PrintLinkedList(linked_list);

    CLOVE_PTR_NE(linked_list, first); 
    CLOVE_PTR_EQ(linked_list, second); 
    CLOVE_PTR_NE(first->node.next, second); 
    CLOVE_PTR_EQ(second->node.next, third); 
    CLOVE_PTR_NE(third->node.next, fourth); 
}

CLOVE_TEST(LinkedList_remove)
{
    string_item_t *linked_list = NULL;
    string_item_t *first = string_item_new("first");
    string_item_t *second = string_item_new("second");
    string_item_t *third = string_item_new("third");
    string_item_t *fourth = string_item_new("fourth");

    list_append((HEAD)&linked_list, (ITEM)first);
    list_append((HEAD)&linked_list, (ITEM)second);
    list_append((HEAD)&linked_list, (ITEM)third);

    list_remove((HEAD)&linked_list, (ITEM)second);

    //PrintLinkedList(linked_list);

    CLOVE_PTR_EQ(linked_list, first); 
    CLOVE_PTR_NE(first->node.next, second); 
    CLOVE_PTR_EQ(first->node.next, third); 
    CLOVE_PTR_NE(second->node.next, third); 
    CLOVE_PTR_NE(third->node.next, fourth);
}

CLOVE_TEST(LinkedList_reverse)
{
    string_item_t *linked_list = NULL;
    string_item_t *first = string_item_new("first");
    string_item_t *second = string_item_new("second");
    string_item_t *third = string_item_new("third");
    string_item_t *fourth = string_item_new("fourth");

    list_append((HEAD)&linked_list, (ITEM)first);
    list_append((HEAD)&linked_list, (ITEM)second);
    list_append((HEAD)&linked_list, (ITEM)third);

    list_reverse((HEAD)&linked_list);

    //PrintLinkedList(third);

    CLOVE_PTR_EQ(first->node.next, NULL);
    CLOVE_PTR_NE(first->node.next, second);  
    CLOVE_PTR_EQ(second->node.next, first); 
    CLOVE_PTR_NE(second->node.next, third); 
    CLOVE_PTR_EQ(third->node.next, second); 
    CLOVE_PTR_NE(third->node.next, fourth);

    //list_reverse((HEAD)&third);

    //PrintLinkedList(linked_list);
}