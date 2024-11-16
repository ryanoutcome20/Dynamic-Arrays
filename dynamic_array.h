#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum DReturns
{
   // Passed.
   SUCCESS = 1,

   // Failed to malloc.
   OUT_OF_MEMORY = 2,

   // You gave a number out of bounds.
   OUT_OF_BOUNDS = 3,

   // You gave an object that doesn't equal the element_size.
   // Typically happens when you give an object the array was
   // not made for.
   INVALID_OBJECT = 4,

   // The array is empty.
   EMPTY = 5
};

typedef struct {
   // Pointer to the array.
   void* data; 

   // Number of elements currently in the array.
   int size;
   
   // Capacity of the array.
   int capacity;

   // Size of each element.
   size_t element_size;

   // Should we be allowed to shrink the array when the highest
   // index is less than 25% of the total allocated space? 
   // Act like this is a bool if you are using stdbool.
   int shrink;
} DynamicArray;

// Basic Operations

/**
 * DInitialize - Initializes a dynamic array based on provided arguments.
 *
 * @array: The dynamic array pointer that you want to be initialized. 
 *   
 * @element_size: The size of whatever elements you plan to store inside
 * of the array (sizeof(int) for example).
 *   
 * @capacity: The initial starting capacity of the array. How many elements
 * can be stored in it without resizing.
 *
 * @return: A DReturns enumerator which will give you the status of the operation.
 */
int DInitialize (DynamicArray* array, size_t element_size, int capacity);

/**
 * DAdd - Adds an element to the dynamic array.
 *
 * @array: The dynamic pointer that you want the object to be added into. 
 *   
 * @object: The object pointer that you want to be added to the end of the array.
 *
 * @return: A DReturns enumerator which will give you the status of the operation.
 */
int DAdd( DynamicArray* array, void* object );

/**
 * DRemove - Removes an element at the provided index.
 *
 * @array: The dynamic array pointer that you want the element to be removed from. 
 *   
 * @index: The index of the object that will be removed. Zero aligned.
 *
 * @return: A DReturns enumerator which will give you the status of the operation.
 */
int DRemove( DynamicArray* array, int index );

// Utility Operations

/**
 * DSize - Gets the total size of the dynamic array. Will be the total allocated not really the total currently stored.
 *
 * @array: The dynamic array you want the size of.
 *
 * @return: A DReturns enumerator which will give you the status of the operation.
 */
int DSize( DynamicArray* array );

/**
 * DIndex - Gets the value at a specific index.
 *
 * @array: The dynamic array you want the value from. 
 *   
 * @index: The index of the object that you will get. Zero aligned.
 *
 * @value: A pointer that will be set to the object that is found. 
 * 
 * @return: A DReturns enumerator which will give you the status of the operation.
 */
int DIndex( DynamicArray* array, int index, void* value );
