#include "clove.h"
#include "sets.h"
#include <stdio.h>


CLOVE_TEST(Sets_search_and_unique_keys)
{
    set_table_t *table = set_table_new(4);
    set_node_t *aa = set_insert(table,"aa",2);
    set_node_t *aa2 = set_insert(table,"aa",2);
    set_node_t *bbb = set_insert(table,"bbb",3);
    set_node_t *cccc = set_insert(table,"cccc",4);
    set_node_t *d = set_insert(table,"d",1);

    CLOVE_PTR_EQ(aa,set_search(table,"aa",2));
    CLOVE_PTR_EQ(aa2,set_search(table,"aa",2));
    CLOVE_PTR_EQ(aa2,aa);
}

CLOVE_TEST(Sets_removal)
{
    set_table_t *table = set_table_new(4);
    set_node_t *aa = set_insert(table,"aa",2);
    set_node_t *bbb = set_insert(table,"bbb",3);
    set_node_t *cccc = set_insert(table,"cccc",4);
    set_node_t *d = set_insert(table,"d",1);

    CLOVE_PTR_EQ(aa,set_search(table,"aa",2));
    CLOVE_PTR_EQ(bbb,set_search(table,"bbb",3));
    CLOVE_PTR_EQ(cccc,set_search(table,"cccc",4));
    
    set_removal(table,"aa",2);
    set_removal(table,"bbb",3);

    CLOVE_PTR_NE(aa,set_search(table,"aa",2));
    CLOVE_PTR_NE(bbb,set_search(table,"bbb",3));
    CLOVE_PTR_EQ(cccc,set_search(table,"cccc",4));
}