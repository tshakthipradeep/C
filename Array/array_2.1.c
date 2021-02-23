/*
 * https://www.geeksforgeeks.org/c-program-cyclically-rotate-array-one/
 * 
 * Program to cyclically rotate an array by one
 * 
 * Given an array, cyclically rotate the array clockwise by one.
 * 
 * Input:  arr[] = {1, 2, 3, 4, 5}
 * Output: arr[] = {5, 1, 2, 3, 4}
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
rotate(int *array, int n) {
    int temp = 0;

    temp = array[n-1];
    
    memcpy(array+1, array, n * sizeof(int));
    array[0] = temp;
}

void
print(int *array, int n) {
    int i = 0;

    for(i=0;i<n;i++) {
        printf("Index %d = %d\n",i,array[i]);
    }
}

int main(int argc, char *arg[]) {
    int input[] = {1, 2, 3, 4, 5};
    rotate(input , sizeof(input)/sizeof(int));
    print(input, sizeof(input)/sizeof(int));
}
