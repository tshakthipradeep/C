/*
 * https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
 * 
 * Find the minimum element in a sorted and rotated array
 * 
 * A sorted array is rotated at some unknown point, find the minimum element in it. 
 * The following solution assumes that all elements are distinct.
 * 
 * Input: {5, 6, 1, 2, 3, 4}
 * Output: 1
 * 
 * Input: {1, 2, 3, 4}
 * Output: 1
 * 
 * Input: {2, 1}
 * Output: 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
min_element(int *array, int n) {
    int i = 0;
    int t = 0;

    for(i=0;i<n;i++) {
        if(array[i] > array[i+1]) {
            t = array[i+1];
            break;
        }
    }

    printf("Smallest element is = %d\n",t);
}



int main(int argc, char *arg[]) {
    int input[] = {5, 6, 1, 2, 3, 4};

    min_element(input, sizeof(input)/sizeof(int));
}
