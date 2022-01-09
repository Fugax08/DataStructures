#include "clove.h"
#include "test_linkedList.h"
#include "test_doubleLinkedList.h"
#include "test_sets.h"
#include "test_dictionary.h"

CLOVE_RUNNER(LinkedList_appendStringItemNew, LinkedList_pop, LinkedList_remove, LinkedList_reverse,
            DoubleLinkedList_append, DoubleLinkedList_remove, DoubleLinkedList_removeFirstItemAndLastItem, DoubleLinkedList_itemInsertAfterAndAfterTail, DoubleLinkedList_itemInsertBefore, DoubleLinkedList_itemInsertBeforeHead, DoubleLinkedList_shuffle,
            Sets_search_and_unique_keys, Sets_removal,
            Dictionaries_search_and_unique_keys, Dictionaries_removal);