/*
    This is an example to showcase the basic usage of dynamic arrays.
*/

#include <stdio.h>
#include "dynamic_array.h"

void Output(DynamicArray* array) {
    for (int i = 0; i < DSize(array); i++) {
        double n;

        DIndex(array, i, &n);

        printf("%f\n", n); // Use %f for double
    }
}

int main(void) {
    DynamicArray array;

    printf("HELLO WORLD!\n");

    DInitialize(&array, sizeof(double), 5);

    for (int i = 0; i < 5; i++) {
        double value = i;

        DAdd(&array, &value);
    }

    Output(&array);

    return 0;
}