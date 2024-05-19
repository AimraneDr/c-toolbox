#include <stdio.h>

#include "Test.h"
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
int test_cleaning();

int main(){    
    test_title("Start LinkedList test proccess ...",0);
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
    result += test_cleaning();
    if(result == 0){
        test_success("All tests had passed successfully.", 1);
    }else{
        test_fail("not all test had succeeded.", 1);
    }
    return 0;
}

int test_creation(){
    LinkedList l1 = LinkedList_create();
    LinkedList l2 = LinkedList_create();
    if(l1.length == 0 && l2.length == 0){
        test_success("creating LinkedLists Test", 2);
        return 0;
    }
    test_fail("creating LinkedLists Test", 2);
    return 1;
}

int test_appending(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListAppend(&l1, &i);
    }
    if(l1.length == 100){
        test_success("appending 100 elements Test", 2);
        return 0;
    }
    test_fail("appending 100 elements Test", 2);
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
        test_success("inserting 200 elements Test", 2);
        return 0;
    }
    test_fail("inserting 200 elements Test", 2);
    return 1;
}

int test_pushing(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListPush(&l1, &i);
    }
    if(l1.length == 100){
        test_success("pushing 100 elements Test", 2);
        return 0;
    }
    test_fail("pushing 100 elements Test", 2);
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
        test_success("deleting 100 elements Test", 2);
        return 0;
    }
    test_fail("deleting 100 elements Test", 2);
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
        test_success("removing 100 elements Test", 2);
        return 0;
    }
    test_fail("removing 100 elements Test", 2);
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
        test_success("shifting 100 elements Test", 2);
        return 0;
    }
    test_fail("shifting 100 elements Test", 2);
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
        test_success("poping 100 elements Test", 2);
        return 0;
    }
    test_fail("poping 100 elements Test", 2);
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
            test_fail("getting elements Test", 2);
            return 1;
        }
    }
    test_success("getting elements Test", 2);
    return 0;
}

int test_cleaning(){
    LinkedList l1 = LinkedList_create();
    for(int i = 0; i < 100; i++){
        LinkedListPush(&l1, &i);
    }
    LinkedList_clean(&l1);
    if(l1.length == 0){
        test_success("cleaning LinkedList Test", 2);
        return 0;
    }
    test_fail("cleaning LinkedList Test", 2);
    return 1;
}