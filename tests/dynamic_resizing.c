/*
    This is an example to showcase how an array will dynamically resize both up and down based
    on what is inside the array.
*/

#include <stdio.h>
#include "dynamic_array.h"

void Output( DynamicArray* array )
{
    for (int i = 0; i < DSize(array); i++)
    {
        int n;

        DIndex(array, i, &n);

        printf("%i\n", n);
    }
}

int main(void)
{
    DynamicArray array;

    DInitialize(&array, sizeof(int), 20);
    
    for(int i = 0; i <= 50; i++) {
        int value = i;

        DAdd(&array, &value);
    }

    printf("%i\n", DSize(&array)); // 51

    // Output(&array);

    for(int i = 0; i <= 40; i++) 
    {
        DRemove(&array, i);
    }

    // Output(&array);

    printf("%i\n", DSize(&array)); // 25

    return 0;
}