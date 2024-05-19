#include "collections/DynamicArray.h"
#include "stdlib.h"
#include <string.h>

typedef unsigned long long u64;

void* __DynamicArray_create(unsigned long long length, unsigned long long block_size){
    u64 header_size = DARRAY_FIELD_LENGTH * sizeof(u64);
    u64 array_size = length * block_size;
    u64* new_array = malloc(header_size + array_size);
    memset(new_array, 0, header_size + array_size);
    new_array[DARRAY_CAPACITY] = length;
    new_array[DARRAY_LENGTH] = 0;
    new_array[DARRAY_BLOCK_SIZE] = block_size;
    return (void*)(new_array + DARRAY_FIELD_LENGTH);
}

void* __DynamicArray_resize(void* arr){
    u64 len = DynamicArray_Length(arr);
    u64 block_size = DynamicArray_BlockSize(arr);
    void* temp = __DynamicArray_create(
        (DARRAY_RESIZE_FACTOR * DynamicArray_Capacity(arr)), 
        block_size
    );

    memcpy(temp, arr,len * block_size);
    __DynamicArray_SetProperty(temp, DARRAY_LENGTH, len);
    DynamicArray_Destroy(arr);
    return temp;
}

void* __DynamicArray_push(void* arr, void* val){
    u64 block_size = DynamicArray_BlockSize(arr);
    u64 length = DynamicArray_Length(arr);
    u64 capacity = DynamicArray_Capacity(arr);
    if(length == capacity){
        arr = __DynamicArray_resize(arr);
    }
    u64 dist = (u64)arr + (length * block_size);
    memcpy((void*)dist, val, block_size);
    __DynamicArray_SetProperty(arr, DARRAY_LENGTH, length + 1);
    return arr;
}

void __DynamicArray_pop(void* arr, void* out){
    u64 block_size = DynamicArray_BlockSize(arr);
    u64 length = DynamicArray_Length(arr);
    u64 addr = (u64)arr + ((length-1) * block_size);
    if(out != (void*)0)
        memcpy(out, (void*)addr, block_size);
    __DynamicArray_SetProperty(arr, DARRAY_LENGTH, length - 1);
}

unsigned long long __DynamicArray_GetProperty(void* arr, DynamicArrayProperty prop){
    u64* h = (u64*)arr - DARRAY_FIELD_LENGTH;
    return h[prop]; 
}

void __DynamicArray_SetProperty(void* arr, DynamicArrayProperty prop, unsigned long long val){
    u64* h = (u64*)arr - DARRAY_FIELD_LENGTH;
    h[prop] = val;
}

void DynamicArray_Destroy(void* arr){
    if(!arr) return;
    u64* header = (u64*)arr - DARRAY_FIELD_LENGTH;
    free(header);
    arr = (void*)0;
}

