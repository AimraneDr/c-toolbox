#ifndef LinkedList_test_h
#define LinkedList_test_h

#include <stdio.h>
#include "collections/LinkedList.h"

/**
 * create [done]
 * append [done]
 * insert [done]
 * push [done]
 * delete [done]
 * remove [done]
 * pop [done]
 * shift [done]
 * get [done]
 * destroy [done]
*/

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
            *(int*)n1->data != indecies[i] || *(double *)n2->data != doubles[i]
        ){
            printf("FAILED to get the right element, or failed to append it\n");
            break;
        }
    }
    printf("all 5 elements retrieved successfully\n");

    //inserting
    int integers[5][2] = {
        {10,121},
        {32,121},
        {40,121},
        {54,121},
        {95,121}
    };
    double doubles2[5][2] = {
        {10,121.f},
        {32,121.f},
        {40,121.f},
        {54,121.f},
        {95,121.f}
    };
    for (int i = 0; i< 5; i++){
        LinkedList_insert(&l1, integers[i][0], sizeof(int), &integers[i][1]);
        LinkedList_insert(&l2, doubles2[i][0], sizeof(double), &doubles2[i][1]);
    }
    for(int i = 0; i < 5; i++){
        LinkedListNode* n1 = LinkedList_get_node(&l1, integers[i][0]);
        LinkedListNode* n2 = LinkedList_get_node(&l2, (int)doubles2[i][0]);
        if(
            *(int*)n1->data != integers[i][1] || *(double *)n2->data != doubles2[i][1]
        ){
            printf("FAILED to get the right element, or failed to append it\n");
            break;
        }
    }
    printf("insert 5 elements and retrive them successfully\n");

    //Tets : Push
    for (int i = 0; i< 5; i++){
        LinkedList_push(&l1, sizeof(int), &integers[i][1]);
        LinkedList_push(&l2, sizeof(double), &doubles2[i][1]);
    }
    for(int i = 0; i < 5; i++){
        LinkedListNode* n1 = LinkedList_get_node(&l1, i);
        LinkedListNode* n2 = LinkedList_get_node(&l2, i);
        if(
            *(int*)n1->data != integers[4 - i][1] || *(double *)n2->data != doubles2[4 - i][1]
        ){
            printf("FAILED to get the right element, or failed to push it\n");
            break;
        }
    }
    printf("push 5 elements and retrive them successfully\n");

    //Test : Remove, shift, pop
    // remove first, mid and last elements
    LinkedListNode* gn1m = LinkedList_get_node(&l1, l1.length / 2);
    LinkedListNode* gn2m = LinkedList_get_node(&l2, l2.length / 2);
    LinkedListNode* gn1f = LinkedList_get_node(&l1, 0);
    LinkedListNode* gn2f = LinkedList_get_node(&l2, 0);
    LinkedListNode* gn1l = LinkedList_get_node(&l1, l1.length - 1);
    LinkedListNode* gn2l = LinkedList_get_node(&l2, l2.length - 1);

    LinkedListNode* r1m = LinkedList_remove(&l1, l1.length / 2);
    LinkedListNode* r2m = LinkedList_remove(&l2, l2.length / 2);
    LinkedListNode* r1f = LinkedList_remove(&l1, 0);
    LinkedListNode* r2f = LinkedList_remove(&l2, 0);
    LinkedListNode* r1l = LinkedList_remove(&l1, l1.length - 1);
    LinkedListNode* r2l = LinkedList_remove(&l2, l2.length - 1);

    if(
        *(int*)gn1m->data  != *(int*)r1m->data ||
        *(double*)gn2m->data  != *(double*)r2m->data ||
        *(int*)gn1f->data  != *(int*)r1f->data ||
        *(double*)gn2f->data  != *(double*)r2f->data ||
        *(int*)gn1l->data  != *(int*)r1l->data ||
        *(double*)gn2l->data  != *(double*)r2l->data 
    ){
        printf("FAILED to remove the right element\n");
    }

    Node_destroy(gn1m);
    Node_destroy(gn2m);
    Node_destroy(gn1f);
    Node_destroy(gn2f);
    Node_destroy(gn1l);
    Node_destroy(gn2l);
    Node_destroy(r1m);
    Node_destroy(r2m);
    Node_destroy(r1f);
    Node_destroy(r2f);
    Node_destroy(r1l);
    Node_destroy(r2l);

    LinkedList_delete(&l1, l1.length / 3);
    LinkedList_delete(&l1, l1.length / 3);
    LinkedList_delete(&l2, l2.length / 3);
    

    printf("\n\tfinal lists length : {l1 : %d, l2 : %d}\n\n", l1.length, l2.length);
    // test : Destroy, Pop
    LinkedList_destroy(&l1);
    LinkedList_destroy(&l2);
    if(l1.length == 0 && l2.length == 0){
        printf("Lists destroyed successfully\n");
    }else{
        printf("FAILED : lists destruction failed, l1 : %d , l2 : %d\n", l1.length, l2.length);
    }
    return 0;
}


#endif