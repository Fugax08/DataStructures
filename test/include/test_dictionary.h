#include "clove.h"
#include "dictionary.h"
#include <stdio.h>


CLOVE_TEST(Dictionaries_search_and_unique_keys)
{
    dictionary_table_t *table = dictionary_table_new(4);
    dictionary_node_t *first = dictionary_insert(table,"first",2,"aa");
    dictionary_node_t *first2 = dictionary_insert(table,"first",2,"aa2");
    dictionary_node_t *second = dictionary_insert(table,"second",3,"bbb");
    dictionary_node_t *third = dictionary_insert(table,"third",4,"cccc");
    dictionary_node_t *fourth = dictionary_insert(table,"fourth",1,"d");

    CLOVE_PTR_EQ(first,dictionary_search(table,"first",2));
    CLOVE_PTR_EQ(first2,dictionary_search(table,"first",2));
    CLOVE_PTR_EQ(first2,first);
}

CLOVE_TEST(Dictionaries_removal)
{
    dictionary_table_t *table = dictionary_table_new(4);
    dictionary_node_t *first = dictionary_insert(table,"first",2,"aa");
    dictionary_node_t *second = dictionary_insert(table,"second",3,"bbb");
    dictionary_node_t *third = dictionary_insert(table,"third",4,"cccc");
    dictionary_node_t *fourth = dictionary_insert(table,"fourth",1,"d");

    CLOVE_PTR_EQ(first,dictionary_search(table,"first",2));
    CLOVE_PTR_EQ(second,dictionary_search(table,"second",3));
    CLOVE_PTR_EQ(third,dictionary_search(table,"third",4));
    
    dictionary_removal(table,"first",2);
    dictionary_removal(table,"second",3);

    CLOVE_PTR_NE(first,dictionary_search(table,"first",2));
    CLOVE_PTR_NE(second,dictionary_search(table,"second",3));
    CLOVE_PTR_EQ(third,dictionary_search(table,"third",4));
}