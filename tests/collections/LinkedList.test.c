#ifndef LinkedList_test_h
#define LinkedList_test_h

#include <stdio.h>
#include "collections/LinkedList.h"


int main(){    
    printf("Start LinkedList test proccess ...\n");
    //creation
    LinkedList l1 = LinkedList_create();
    printf("first list created\n");
    LinkedList l2 = LinkedList_create();
    printf("second list created\n");

    int val = 0;
    double v = 0.0f;
    for (int i = 0; i < 100; i++)
    {
        LinkedListAppend(&l1, &val);
        LinkedListAppend(&l2, &v);
        val+=1;
        v+=1.f;
    }
    if(
        l1.length != 100 || l2.length != 100
    ){
        printf("FAILED : append all elements\n");
    }
    printf("100 elements are appended to the lists\n");

    int indecies[5] = {11, 24, 9, 86, 64};
    double doubles[5] = {11.f, 24.f, 9.f, 86.f, 64.f};
    for(int i = 0; i < 5; i++){
        LinkedListNode* n1 = LinkedList_get_node(&l1, indecies[i]);
        LinkedListNode* n2 = LinkedList_get_node(&l2, (int)doubles[i]);
        if(
            *(int*)n1->data != indecies[i] || *(double *)n2->data != (double)doubles[i]
        ){
            printf("FAILED to get the right element, or failed to append it\n");
            break;
        }
    }
    printf("all 5 elements retrieved successfullyn");

    return 0;
}


#endif