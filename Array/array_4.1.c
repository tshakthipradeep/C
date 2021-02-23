/*
 * https://www.geeksforgeeks.org/quickly-find-multiple-left-rotations-of-an-array/
 * 
 * Quickly find multiple left rotations of an array
 * 
 * Given an array of size n and multiple values around which we need to left rotate the array. 
 * How to quickly find multiple left rotations?
 * 
 * Input : arr[] = {1, 3, 5, 7, 9}
 * k1 = 1
 * k2 = 3
 * k3 = 4
 * k4 = 6
 * Output : 3 5 7 9 1
 *          7 9 1 3 5
 *          9 1 3 5 7
 *          3 5 7 9 1
 * Input : arr[] = {1, 3, 5, 7, 9}
 * k1 = 14
 * Output : 9 1 3 5 7
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
print(int *array, int n) {
    int i = 0;

    for(i=0;i<n;i++) {
        printf("Index %d = %d\n",i,array[i]);
    }
}

void
rotate(int *array, int d, int n) {
    int rotations = 0;
    int *temp = NULL;

    if(d <= n) {
        rotations = d; 
    } else {
        rotations = d % n;
    }

    printf("rotations = %d\n", rotations);

    temp = (int *)malloc(sizeof(int) * rotations);
    if(temp == NULL) {
        printf("Could not allocate memory\n");
        return;
    }

    memcpy(temp, array, sizeof(int) * rotations);
    memcpy(array, array+rotations, (sizeof(int)*(n-rotations)));
    memcpy(array+n-rotations, temp, sizeof(int) * rotations);
}



int main(int argc, char *arg[]) {
    int input[] = {1, 3, 5, 7, 9};

    rotate(input, 6, sizeof(input)/sizeof(int));
    print(input, sizeof(input)/sizeof(int));
}
