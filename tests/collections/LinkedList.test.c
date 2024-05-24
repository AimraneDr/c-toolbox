#include <stdio.h>

#include "Test.h"
#include "collections/LinkedList.h"

int test_creation(void **data);
int test_appending(void **data);
int test_inserting(void **data);
int test_pushing(void **data);
int test_deleting(void **data);
int test_removing(void **data);
int test_shifting(void **data);
int test_poping(void **data);
int test_getting(void **data);
int test_cleaning(void **data);

int main()
{
    const int subTestCount = 9;
    Test test = {
        .title = "Linked List",
        .data = 0,
        .subTestsCount = subTestCount,
        .subTests = test_create_arr(subTestCount)};

    
    test_register(test.subTests, 0, "Creating LinkedList", 0, test_creation);
    test_register(test.subTests, 1, "Appending elements to LinkedList", 0, test_appending);
    test_register(test.subTests, 2, "Inserting elements in LinkedList", 0, test_inserting);
    test_register(test.subTests, 3, "Pushing elements to LinkedList", 0, test_pushing);
    test_register(test.subTests, 4, "Deleting elements from LinkedList", 0, test_deleting);
    test_register(test.subTests, 5, "Removing elements from LinkedList", 0, test_removing);
    test_register(test.subTests, 6, "Poping elements from LinkedList", 0, test_poping);
    test_register(test.subTests, 7, "Getting elements from LinkedList", 0, test_getting);
    test_register(test.subTests, 8, "Cleaning LinkedList", 0, test_cleaning);

    test_run(&test);
    test_clean(&test);
    return 0;
}

int test_creation(void **data)
{
    LinkedList l1 = LinkedList_create();
    LinkedList l2 = LinkedList_create();
    return l1.length == 0 && l2.length == 0 ? 1 : 0;
}

int test_appending(void **data)
{
    LinkedList l1 = LinkedList_create();
    for (int i = 0; i < 100; i++)
    {
        LinkedListAppend(&l1, &i);
    }
    return l1.length == 100 ? 1 : 0;
}

int test_inserting(void **data)
{
    LinkedList l1 = LinkedList_create();
    int j = 0;
    for (int i = 0; i < 200; i += 2)
    {
        LinkedListInsert(&l1, &i, j);
        int i1 = i + 1;
        LinkedListInsert(&l1, &i1, j);
        j++;
    }
    return l1.length == 200 ? 1 : 0;
}

int test_pushing(void **data)
{
    LinkedList l1 = LinkedList_create();
    for (int i = 0; i < 100; i++)
    {
        LinkedListPush(&l1, &i);
    }
    return l1.length == 100 ? 1 : 0;
}

int test_deleting(void **data)
{
    LinkedList l1 = LinkedList_create();
    for (int i = 0; i < 100; i++)
    {
        LinkedListPush(&l1, &i);
    }
    while (l1.length > 1)
    {
        LinkedList_delete(&l1, 1);
    }
    if (l1.length == 1)
    {
        LinkedList_delete(&l1, 0);
    }
    return l1.length == 0 ? 1 : 0;
}

int test_removing(void **data)
{
    LinkedList l1 = LinkedList_create();
    for (int i = 0; i < 100; i++)
    {
        LinkedListPush(&l1, &i);
    }
    while (l1.length > 1)
    {
        Node_destroy(LinkedList_remove(&l1, 1));
    }
    if (l1.length == 1)
    {
        Node_destroy(LinkedList_remove(&l1, 0));
    }
    return l1.length == 0 ? 1 : 0;
}

int test_shifting(void **data)
{
    LinkedList l1 = LinkedList_create();
    for (int i = 0; i < 100; i++)
    {
        LinkedListPush(&l1, &i);
    }
    while (l1.length > 0)
    {
        Node_destroy(LinkedList_shift(&l1));
    }
    return l1.length == 0 ? 1 : 0;
}

int test_poping(void **data)
{
    LinkedList l1 = LinkedList_create();
    for (int i = 0; i < 100; i++)
    {
        LinkedListPush(&l1, &i);
    }
    while (l1.length > 0)
    {
        Node_destroy(LinkedList_pop(&l1));
    }
    return l1.length == 0 ? 1 : 0;
}

int test_getting(void **data)
{
    LinkedList l1 = LinkedList_create();
    for (int i = 0; i < 100; i++)
    {
        LinkedListAppend(&l1, &i);
    }
    for (int i = 0; i < 100; i++)
    {
        int val = *(int *)LinkedList_get_node(&l1, i)->data;

        if (val != i)
            return 0;
    }
    //success
    return 1;
}

int test_cleaning(void **data)
{
    LinkedList l1 = LinkedList_create();
    for (int i = 0; i < 100; i++)
    {
        LinkedListPush(&l1, &i);
    }
    LinkedList_clean(&l1);
    return l1.length == 0 ? 1 : 0;
}