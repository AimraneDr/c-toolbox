#include <stdio.h>

#include "Test.h"
#include "collections/DynamicArray.h"

/* DECLARATIONS */
int test_creation(void** arr);
int test_pushing(void** arr);
int test_popping(void** arr);

/* MAIN PROGRAM */

int main(void){

    int* arr = 0;
    Test test = {
        .title = "Dynamic List",
        .data = &arr,
        .subTestsCount = 3,
        .subTests = test_create_arr(3)
    };

    test_register(test.subTests, 0, "Creating Dynamic List", &arr, test_creation);
    test_register(test.subTests, 1, "Pushing Elements in Dynamic List", &arr, test_pushing);
    test_register(test.subTests, 2, "Popping Elements from Dynamic List", &arr, test_popping);

    test_run(&test);
    test_clean(&test);

    DynamicArray_Destroy(arr);
    return 0;
}

/* DEFINATIONS */

int test_creation(void** arr){
    *arr = DynamicArray_Create(int);
    if(!*arr && DynamicArray_Capacity(arr) != DARRAY_INITIAL_CAPACITY){
        return 0;
    }
    else
    {
        int* arr0 = DynamicArray_Reserve(10, int);
        if(!arr0 && DynamicArray_Capacity(arr0) != 10){
            return 0;
        }
        return 1;
    }
}

int test_pushing(void** arr){
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
        return 1;
    }
    else
    {
        return 0;
    }
}

int test_popping(void** arr){
    int len = (int) DynamicArray_Length(*arr);
    for(int i=0; i<len; i++){
        DynamicArray_Pop(*arr, (void*)0);
    }
    len = (int) DynamicArray_Length(*arr);
    if(len == 0){
        return 1;
    }else{
        return 0;
    }
}
