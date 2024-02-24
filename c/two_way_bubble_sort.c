#include <stdio.h>
#include <stdlib.h>

int main() {
    int y[50] = {50, 29, 10, 35, 14, 42, 3, 25, 38, 43, 15, 9, 46, 22, 13, 8, 30, 6, 45, 2, 41, 18, 23, 36, 28, 7, 5, 48, 44, 21, 26, 16, 39, 31, 17, 49, 37, 11, 33, 34, 27, 47, 4, 24, 1, 19, 20, 40, 12, 32};
    int array_size = sizeof(y) / sizeof(y[0]);
    printf("%d \n", array_size/2);
    int z = array_size - 1;
    int centre = (array_size - 1) / 2;
    for (int a = 0; a < z; a++) {
        //(a <= centre || z > centre) makes sure that both if blocks are executed, untill both blocks have checked upto the centre of the array.
        if (y[a] > y[a+1] && (a <= centre || z > centre)) {
            
            int b = y[a];
            int c = y[a+1];
            
            y[a] = c;
            y[a+1] = b;
            
            a = -1;
        }

        if (y[z-1] > y[z] && (z > centre || a <= centre)) {
            int x = y[z];
            int w = y[z-1];
            //printf("\n %d %d : %d %d\n", y[z-1], y[z], z-1, z);
            
            y[z] = w;
            y[z-1] = x;

            z = array_size - 1;
        } else {
            z--;
        }
    }
    
    for (int i = 0; i < array_size; i++) {
        printf("%d, " ,y[i]);
    }
    return 0;
}
