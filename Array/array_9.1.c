/*
 * https://www.geeksforgeeks.org/rearrange-array-arri/
 * 
 * Rearrange an array such that arr[i] = i
 * 
 * Given an array of elements of length N, ranging from 0 to N – 1. All elements may 
 * not be present in the array. If the element is not present then there will be -1 
 * present in the array. Rearrange the array such that A[i] = i and if i is not present, 
 * display -1 at that place.
 * 
 * Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
 * Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]
 *
 * Input : arr = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
 *              11, 10, 9, 5, 13, 16, 2, 14, 17, 4}
 * Output : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
 *           11, 12, 13, 14, 15, 16, 17, 18, 19]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
rearrange(int *array, int n) {
    int *temp = NULL;
    int ind = 0;

    temp = (int *)malloc(sizeof(int) *  n);
    if(temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for(ind=0;ind<n;ind++) {
        temp[ind] = -1;
    }

    for(ind=0;ind<n;ind++) {
        if(array[ind] != -1) {
            temp[array[ind]] = array[ind];
        }
    }

    memcpy(array,temp,n*sizeof(int));
}

void
print(int *array, int n) {
    int i = 0;

    for(i=0;i<n;i++) {
        printf("Index %d = %d\n",i,array[i]);
    }
}

int main(int argc, char *arg[]) {
    int arr[] = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8, 
                11, 10, 9, 5, 13, 16, 2, 14, 17, 4};

    rearrange(arr, sizeof(arr)/sizeof(int));
    print(arr, sizeof(arr)/sizeof(int));
}
