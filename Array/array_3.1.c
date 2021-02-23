/*
 * https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/
 * 
 * Find the Rotation Count in Rotated Sorted array
 * 
 * Consider an array of distinct numbers sorted in increasing order. 
 * The array has been rotated (clockwise) k number of times. Given such an array, 
 * find the value of k.
 * 
 * Input : arr[] = {15, 18, 2, 3, 6, 12}
 * Output: 2
 * Input : arr[] = {7, 9, 11, 12, 5}
 * Output: 4
 * Input: arr[] = {7, 9, 11, 12, 15};
 * Output: 0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
rotated_by(int *array, int n) {
    int i = 0;

    for(i=0;i<n-1;i++) {
        if(array[i] > array[i+1]) {
            printf("Array has been rotated %d times\n",i+1);
            return;
        }
    }

    printf("Array has been rotated 0 times\n");
}

int main(int argc, char *arg[]) {
    int input[] = {7, 9, 11, 12, 15};

    rotated_by(input , sizeof(input)/sizeof(int));
}
