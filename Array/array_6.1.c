/*
 * https://www.geeksforgeeks.org/find-a-rotation-with-maximum-hamming-distance/
 * 
 * Find a rotation with maximum hamming distance
 * 
 * Given an array of n elements, create a new array which is a rotation of given array 
 * and hamming distance between both the arrays is maximum. Hamming distance between 
 * two arrays or strings of equal length is the number of positions at which the 
 * corresponding character(elements) are different.
 * 
 * Note: There can be more than one output for the given input.
 * 
 * Input :  1 4 1
 * Output :  2
 * Explanation:  
 * Maximum hamming distance = 2
 * We get this hamming distance with 4 1 1 or 1 1 4
 * 
 * Input :  2 4 8 0
 * Output : 4
 * 
 * Explanation:
 * Maximum hamming distance = 4
 * We get this hamming distance with 4 8 0 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
print(int *array_a, int *array_b, int n, int d) {
    int i = 0;

    printf("Hamming distance for follow array is %d\n",d);
    for(i=0;i<n;i++) {
        printf("%d ",array_a[i]);
    }
    printf("\n");
    for(i=0;i<n;i++) {
        printf("%d ",array_b[i]);
    }
    printf("\n");
}

int 
hamming_distance(int *array_a, int *array_b, int n) {
    int i = 0;
    int d = 0;

    for(i=0; i<n; i++) {
        if(array_a[i] != array_b[i]) {
            d++;
        }
    }

    return d;
}

void
rotate(int *array_a, int *array_b, int n) {
    int t = 0;
    int d = 0;
    int i = 0;

    memcpy(array_b, array_a, sizeof(int) * n);

    do {
        t = array_b[0];
        
        for(i=0;i<n-1;i++) {
            array_b[i] = array_b[i+1];
        }
        array_b[n-1] = t;

        d = hamming_distance(array_a, array_b, n);
        print(array_a, array_b, n, d);
    } while(d != 0);
}

int main(int argc, char *arg[]) {
    int array_a[] = {2, 4, 8, 0};
    int array_b[] = {0, 0, 0, 0};

    rotate(array_a, array_b, sizeof(array_a)/sizeof(int));
}
