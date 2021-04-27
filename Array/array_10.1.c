/*
 * https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
 * 
 * Write a program to reverse an array or string
 * 
 * Given an array (or string), the task is to reverse the array/string
 * 
 * Input  : arr[] = {1, 2, 3}
 * Output : arr[] = {3, 2, 1}
 *
 * Input :  arr[] = {4, 5, 1, 2}
 * Output : arr[] = {2, 1, 5, 4}
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
rotate(int *array, int n) {
    int mid = 0;
    int ind = 0;
    int tmp = 0;

    mid = n / 2;

    for(ind=0;ind<mid;ind++) {
        tmp = array[ind];
        array[ind] = array[n-1-ind];
        array[n-1-ind] = tmp;
    }
}

void
print(int *array, int n) {
    int i = 0;

    for(i=0;i<n;i++) {
        printf("Index %d = %d\n",i,array[i]);
    }
}

int main(int argc, char *arg[]) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    rotate(arr, sizeof(arr)/sizeof(int));
    print(arr, sizeof(arr)/sizeof(int));
}
