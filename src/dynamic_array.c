#include "dynamic_array.h"

// Basic Operations

int DInitialize( DynamicArray* array, size_t element_size, int capacity )
{
    array->data = malloc(capacity * element_size);
    
    if (array->data == NULL) 
    {
        return OUT_OF_MEMORY;
    }

    array->size = 0;
    array->capacity = capacity;
    array->element_size = element_size;

    return SUCCESS;
}

int DAdd( DynamicArray* array, void* object )
{
    if (array->capacity <= array->size)
    {
        // We need to dynamically allocate more space for this array.

        // Allocate space under the Exponential Growth principal.
        array->capacity *= 2;

        // Call realloc and add more space to accommodate for the growth. 
        array->data = realloc(array->data, array->capacity * array->element_size);

        if (array->data == NULL) 
        {
            return OUT_OF_MEMORY;
        }
    }

    // Calculate the target address.
    void* target = (char*)array->data + (array->size * array->element_size);
    
    // Copy over the data.
    memcpy(target, object, array->element_size);
    
    array->size++;

    return SUCCESS;
}

int DRemove( DynamicArray* array, int index )
{
    if (index < 0 || index >= array->size) 
    {
        return OUT_OF_BOUNDS;
    }

    // Get the address of the index we want to remove.
    void* target = (char*)array->data + (index * array->element_size);
    
    // Get the address of the next element.
    void* next = (char*)target + array->element_size;

    // Move everything to the left to fix the order.
    memmove(target, next, (array->size - index - 1) * array->element_size);
    
    array->size--;

    if (array->size < array->capacity / 4 && array->capacity > 4) 
    {
        if (array->shrink == 0)
            return SUCCESS;

        // Shrink the capacity in half.
        array->capacity /= 2;

        // Reallocate.
        array->data = realloc(array->data, array->capacity * array->element_size);

        if (array->data == NULL) 
        {
            return OUT_OF_MEMORY;
        }
    }

    return SUCCESS;
}

// Utility Operations

int DFree( DynamicArray* array )
{
    free(array->data);

    array->data = NULL;
    
    array->size = 0;
    array->capacity = 0;

    return SUCCESS;
}

int DSize( DynamicArray* array )
{
    return array->size;
}

int DIndex( DynamicArray* array, int index, void* value )
{
    if (index < 0 || index >= array->size) 
    {
        return OUT_OF_BOUNDS;
    }

    // Same way its calculated under the hood in C.
    void* source = (char*)array->data + (index * array->element_size);

    // Copy over the memory into your value address.
    memcpy(value, source, array->element_size);

    return SUCCESS;
}