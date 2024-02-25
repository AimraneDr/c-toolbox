/**
 * @file DynamicArray.h
 * @brief Description
 * @date 2024-01-27
 * @author aimrane-dr aimranedr@gmail.com
*/

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef enum _DynamicArrayProperty{
    DARRAY_CAPACITY,
    DARRAY_LENGTH,
    DARRAY_BLOCK_SIZE,
    DARRAY_FIELD_LENGTH
}DynamicArrayProperty;

#define DARRAY_INITIAL_CAPACITY 1
#define DARRAY_RESIZE_FACTOR 2

// Internal
void* __DynamicArray_create(unsigned long long length, unsigned long long block_size);
void* __DynamicArray_resize(void* arr);
void* __DynamicArray_push(void* arr, void* val);
void __DynamicArray_pop(void* arr, void* out);
unsigned long long __DynamicArray_GetProperty(void* arr, DynamicArrayProperty prop);
void __DynamicArray_SetProperty(void* arr, DynamicArrayProperty prop, unsigned long long val);

// Public
void DynamicArray_Destroy(void* arr);

#define DynamicArray_Create(type) \
    (type*)__DynamicArray_create(DARRAY_INITIAL_CAPACITY, sizeof(type))

#define DynamicArray_Reserve(capacity, type) \
    (type*)__DynamicArray_create(capacity, sizeof(type))

#define DynamicArray_Push(array, value)           \
    {                                       \
        typeof(value) temp = value;         \
        array = __DynamicArray_push(array, &temp); \
    }

#define DynamicArray_Pop(array, value_ptr) \
    __DynamicArray_pop(array, value_ptr)

#define DynamicArray_Length(arr)\
    __DynamicArray_GetProperty(arr, DARRAY_LENGTH)

#define DynamicArray_Capacity(arr)\
    __DynamicArray_GetProperty(arr, DARRAY_CAPACITY)

#define DynamicArray_BlockSize(arr)\
    __DynamicArray_GetProperty(arr, DARRAY_BLOCK_SIZE)

#endif //DYNAMIC_ARRAY_H