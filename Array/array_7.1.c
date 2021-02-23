/*
 * https://www.geeksforgeeks.org/queries-left-right-circular-shift-array/
 * 
 * Queries on Left and Right Circular shift on array
 * 
 * Given an array A of N integers. There are three type of type of commands:

 * 1 x : Right Circular Shift the array x times. If an array is a[0], a[1], …., a[n – 1], 
 * then after one right circular shift the array will become a[n – 1], a[0], a[1], …., a[n – 2].
 * 
 * 2 y : Left Circular Shift the array y times. If an array is a[0], a[1], …., a[n – 1], 
 * then after one right circular shift the array will become a[1], …., a[n – 2], a[n – 1], a[0].
 * 
 * 3 l r : Print the sum of all integers in the subarray a[l…r] (l and r inclusive).
 * 
 * Given Q queries, the task is execute each query.
 * 
 * Input : n = 5, arr[] = { 1, 2, 3, 4, 5 }
 * Query 1 = { 1, 3 }
 * Query 2 = { 3, 0, 2 }
 * Query 3 = { 2, 1 }
 * Query 4 = { 3, 1, 4 }
 * 
 * Output : 12
 *          11
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int arr[] = { 1, 2, 3, 4, 5 };
    int siz = sizeof(arr)/sizeof(int);
    int rot = 0;
    int pos = 0;
    int opt = 0;
    int lef = 0;
    int rig = 0;
    int sum = 0;
    int ind = 0;
    int i = 0;

    printf("1 X -> Right circular shift by X positions\n");
    printf("2 Y -> Left circular shift by Y positions\n");
    printf("3 L R -> Print the sum of all integers in the subarray a[l…r]\n");

    while(1) {
        printf("Select option 1 to 3 : ");
        scanf("%d",&opt);

        if(opt == 1 || opt == 2) {
            printf("Enter Position : ");
            scanf("%d",&pos);
        } else if(opt == 3) {
            printf("Enter Left Index : ");
            scanf("%d",&lef);
            printf("Enter Right Index : ");
            scanf("%d",&rig);
        }

        switch(opt) {
            case 1: rot += pos; 
                    printf("Rotated by %d positions\n",rot);
                    break;
            case 2: rot -= pos;
                    printf("Rotated by %d positions\n",rot);
                    break;
            case 3: if (rot > siz)
                        rot = rot % siz;
                    if (rot < -siz) 
                        rot = rot % -siz;
                    printf("Total rotations is = %d\n",rot);
                    
                    if(rot > 0)
                        ind = siz - rot;
                    if(rot < 0)
                        ind = -rot;
                    printf("Starting index is = %d\n",ind);
                    sum = 0;
                    for(i=lef;i<=rig;i++) {
                        ind+=lef;
                        sum += arr[ind++];
                        if(ind == siz) 
                            ind = 0;
                    }
                    printf("Sum = %d\n",sum);
                    break;

            default: break;
        }
    }
}
