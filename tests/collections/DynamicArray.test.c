#include <stdio.h>

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
    printf("test dynamic list creating...\n");
    *arr = DynamicArray_Create(int);
    if(!*arr && DynamicArray_Capacity(arr) != DARRAY_INITIAL_CAPACITY){
        printf("faild creating a dynamic array\n");
    }else{
        printf("creating dynamic array test succeeded!\n");
    }

    printf("test dynamic list reserving...\n");
    int* arr0 = DynamicArray_Reserve(10, int);
    if(!arr0 && DynamicArray_Capacity(arr0) != 10){
        printf("faild reserving a dynamic array\n");
    }else{
        printf("reserving dynamic array test succeeded!\n");
    }
}

void test_pushing(void** arr){
    printf("test pushing elems..\n");
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
        printf("pushing test succeeded!\n");
    }else{
        printf("pushing test failed!\n");
    }

}

void test_popping(void** arr){
    int len = (int) DynamicArray_Length(*arr);
    for(int i=0; i<len; i++){
        DynamicArray_Pop(*arr, (void*)0);
    }
    len = (int) DynamicArray_Length(*arr);
    if(len == 0){
        printf("popping test succeeded!\n");
    }else{
        printf("popping test failed !\n");
    }
}
