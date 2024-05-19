#include <stdio.h>

#include "Test.h"
#include "collections/DynamicArray.h"

void test_creation(void** arr);
void test_pushing(void** arr);
void test_popping(void** arr);
int main(void){
    int* arr = 0;
    test_creation(&arr);
    test_pushing(&arr);
    test_popping(&arr);
    DynamicArray_Destroy(arr);
    return 0;
}

void test_creation(void** arr){
    test_title("test dynamic list creating...", 0);
    *arr = DynamicArray_Create(int);
    if(!*arr && DynamicArray_Capacity(arr) != DARRAY_INITIAL_CAPACITY){
        test_fail("failed creating a dynamic array", 1);
    }else{
        test_success("creating dynamic array test succeeded!", 1);
    }

    test_title("test dynamic list reserving...", 0);
    int* arr0 = DynamicArray_Reserve(10, int);
    if(!arr0 && DynamicArray_Capacity(arr0) != 10){
        test_fail("faild reserving a dynamic array", 1);
    }else{
        test_success("reserving dynamic array test succeeded!", 1);
    }
}

void test_pushing(void** arr){
    test_title("test pushing elems..", 0);
    unsigned long long count = 28;
    int samples[] = {
        0,1,2,3,4,
        5,6,7,8,9,
        0,1,2,3,4,
        5,6,7,8,9,
        0,1,2,3,4,
        4,4,5
    };
    for(unsigned long long i=0; i < count; i++){
        DynamicArray_Push(*arr, samples[i]);
    }
    if(DynamicArray_Capacity(*arr) == 32 && DynamicArray_Length(*arr) == count){
        test_success("pushing test succeeded!", 1);
    }else{
        test_fail("pushing test failed!", 1);
    }

}

void test_popping(void** arr){
    test_title("test popping elems..", 0);
    int len = (int) DynamicArray_Length(*arr);
    for(int i=0; i<len; i++){
        DynamicArray_Pop(*arr, (void*)0);
    }
    len = (int) DynamicArray_Length(*arr);
    if(len == 0){
        test_success("popping test succeeded!", 1);
    }else{
        test_fail("popping test failed !", 1);
    }
}
