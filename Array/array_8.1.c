/*
 * https://www.geeksforgeeks.org/find-element-given-index-number-rotations/
 * 
 * Find element at given index after a number of rotations
 * 
 * An array consisting of N integers is given. There are several Right Circular 
 * Rotations of range[L..R] that we perform. After performing these rotations, 
 * we need to find element at a given index.
 * 
 * Input : arr[] : {1, 2, 3, 4, 5}
 *         ranges[] = { {0, 2}, {0, 3} }
 *         index : 1
 * Output : 3
 * 
 * Explanation : After first given rotation {0, 2}
 *               arr[] = {3, 1, 2, 4, 5}
 *               After second rotation {0, 3} 
 *               arr[] = {4, 3, 1, 2, 5}
 * 
 * After all rotations we have element 3 at given index 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
rotate(int *array, int n, int l, int r) {
    int temp = 0;

    if((l < 0) || (r > n) || (l == r))
        return;

    temp = array[r];
    
    memcpy(array+l+1, array+l, ((r-l) * sizeof(int)));
    array[l] = temp;
}

void
print(int *array, int n) {
    int i = 0;

    for(i=0;i<n;i++) {
        printf("Index %d = %d\n",i,array[i]);
    }
}

int main(int argc, char *arg[]) {
    int arr[] = {1, 2, 3, 4, 5};
    int lef = 0;
    int rig = 0;
    int ind = 0;


    lef = 0; rig = 2;
    rotate(arr , sizeof(arr)/sizeof(int), lef, rig);

    lef = 0; rig = 3;
    rotate(arr , sizeof(arr)/sizeof(int), lef, rig);
    
    print(arr, sizeof(arr)/sizeof(int));

    printf("Value at arr[%d] = %d\n", ind, arr[ind]);
}
