#include <stdio.h>

int main() {
    int y[49] = {29, 10, 35, 14, 42, 3, 25, 38, 43, 15, 9, 46, 22, 13, 8, 30, 6, 45, 2, 41, 18, 23, 36, 28, 7, 5, 48, 44, 21, 26, 16, 39, 31, 17, 49, 37, 11, 33, 34, 27, 47, 4, 24, 1, 19, 20, 40, 12, 32};
    int array_size = sizeof(y) / sizeof(y[0]);

    for (int i = 0; i < array_size - 1; i++ ) {
        if (y[i] > y[i + 1]) {
            int c = y[i];
            int d = y[i + 1];
            y[i] = d;
            y[i + 1] = c;
            //using -1 instead of 0 because after incremenenting we want to start from index 0 not index 1.
            i = -1;
        } 
    }
    for (int i = 0; i < array_size; i++) {
        printf( " %d" ,y[i]);
    }
}
