#include <stdio.h>
#include "collections/LinkedList.h"

int test_creation();
int test_appending();
int test_inserting();
int test_pushing();
int test_deleting();
int test_removing();
int test_shifting();
int test_poping();
int test_getting();
int test_destroying();

int main(){    
    printf("Start LinkedList test proccess ...\n\n");
    int result = 0;
    result += test_creation();
    result += test_appending();
    result += test_inserting();
    result += test_pushing();
    result += test_deleting();
    result += test_removing();
    result += test_shifting();
    result += test_poping();
    result += test_getting();
    result += test_destroying();
    if(result == 0){
        printf("\nAll tests had passed successfully.\n\n");
    }else{
        printf("\n%d tests had failed out of 10.\n\n", result);
    }
    return 0;
}

int test_creation(){
    LinkedList l1 = LinkedList_create();
    LinkedList l2 = LinkedList_create();
    if(l1.length == 0 && l2.length == 0){
        printf("[ SUCCESS ]\tcreating LinkedLists Test\n");
        return 0;
    }
    printf("[ FAILED ]\tcreating LinkedLists Test\n");
    return 1;
}

int test_appending(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListAppend(&l1, &i);
    }
    if(l1.length == 100){
        printf("[ SUCCESS ]\tappending 100 elements Test\n");
        return 0;
    }
    printf("[ FAILED ]\tappending 100 elements Test\n");
    return 1;
}

int test_inserting(){
    LinkedList l1 = LinkedList_create();
    int j =0;
    for(int i = 0; i < 200; i+=2){
        LinkedListInsert(&l1, &i, j);
        int i1 = i+1; 
        LinkedListInsert(&l1, &i1, j);
        j++;
    }
    if(l1.length == 200){
        printf("[ SUCCESS ]\tinserting 200 elements Test\n");
        return 0;
    }
    printf("[ FAILED ]\tinserting 200 elements Test\n");
    return 1;
}

int test_pushing(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListPush(&l1, &i);
    }
    if(l1.length == 100){
        printf("[ SUCCESS ]\tpushing 100 elements Test\n");
        return 0;
    }
    printf("[ FAILED ]\tpushing 100 elements Test\n");
    return 1;
}

int test_deleting(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListPush(&l1, &i);
    }

    while(l1.length > 1){
        LinkedList_delete(&l1, 1);
    }
    if(l1.length == 1){
        LinkedList_delete(&l1, 0);
    }
    if(l1.length == 0){
        printf("[ SUCCESS ]\tdeleting 100 elements Test\n");
        return 0;
    }
    printf("[ FAILED ]\tdeleting 100 elements Test\n");
    return 1;
}

int test_removing(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListPush(&l1, &i);
    }

    while(l1.length > 1){
        Node_destroy(LinkedList_remove(&l1, 1));
    }
    if(l1.length == 1){
        Node_destroy(LinkedList_remove(&l1, 0));
    }
    if(l1.length == 0){
        printf("[ SUCCESS ]\tremoving 100 elements Test\n");
        return 0;
    }
    printf("[ FAILED ]\tremoving 100 elements Test\n");
    return 1;
}

int test_shifting(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListPush(&l1, &i);
    }

    while(l1.length > 0){
        Node_destroy(LinkedList_shift(&l1));
    }
    if(l1.length == 0){
        printf("[ SUCCESS ]\tshifting 100 elements Test\n");
        return 0;
    }
    printf("[ FAILED ]\tshifting 100 elements Test\n");
    return 1;
}

int test_poping(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListPush(&l1, &i);
    }

    while(l1.length > 0){
        Node_destroy(LinkedList_pop(&l1));
    }
    if(l1.length == 0){
        printf("[ SUCCESS ]\tpoping 100 elements Test\n");
        return 0;
    }
    printf("[ FAILED ]\tpoping 100 elements Test\n");
    return 1;
}

int test_getting(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListAppend(&l1, &i);
    }

    for(int i = 0; i < 100; i++){
        int val = *(int*)LinkedList_get_node(&l1, i)->data;
        if(val != i){
            printf("[ FAILED ]\tgetting elements Test\n");
            return 1;
        }
    }
    printf("[ SUCCESS ]\tgetting elements Test\n");
    return 0;
}

int test_destroying(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListPush(&l1, &i);
    }

    LinkedList_destroy(&l1);
    if(l1.length == 0){
        printf("[ SUCCESS ]\tdestroying LinkedList Test\n");
        return 0;
    }
    printf("[ FAILED ]\tdestroying LinkedList Test\n");
    return 1;
}