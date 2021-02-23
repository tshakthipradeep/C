/*
 * https://www.geeksforgeeks.org/array-rotation/
 * 
 * Program for array rotation
 * 
 * Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements. 
 * Input = 1,2,3,4,5,6,7
 * Rotation of the above array by 2 will make array
 * Output = 3,4,5,6,7,1,2
 */

#include <stdio.h>
#include <stdlib.h>

void
rotate(int *array, int d, int n) {
    int *temp = NULL;
    int i = 0;
    int j = 0;

    temp = (int *)malloc(sizeof(int) * d);
    if(temp == NULL) {
        printf("Memory allocatoion failed\n");
        return;
    }

    for(i=0;i<d;i++) {
        temp[i] = array[i];
    }

    for(i=0,j=d;j<n;i++,j++) {
        array[i] = array[j];
    }

    for(j=0;i<n;i++,j++) {
        array[i] = temp[j];
    }

    if(temp != NULL)
        free(temp);
}

void
print(int *array, int n) {
    int i = 0;

    for(i=0;i<n;i++) {
        printf("Index %d = %d\n",i,array[i]);
    }
}

int main(int argc, char *arg[]) {
    int input[] = {1,2,3,4,5,6,7};
    rotate(input, 2, sizeof(input)/sizeof(int));
    print(input, sizeof(input)/sizeof(int));
}
