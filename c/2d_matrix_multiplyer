#include <stdio.h>
#include <stdlib.h>

int main() {
    int m[2][3] = {{1,2,3},{4,5,6}};        //matrix 1
    int n[3][2] = {{1,1},{2,2},{3,3}};        //matrix 2
    
    //number of rows and columns of m.Also number of elements
    int rows_one = sizeof(m) / sizeof(m[0]);
    
    //number of rows and columns of n
    int rows_two = sizeof(n) / sizeof(n[0]);
    int columns_two = sizeof(n[0]) / sizeof(n[0][0]);
    
    //RESULT MATRIX
    //length of result matrix shall be influenced by rows_one * columns_two
    int final_results[rows_one][columns_two];
    int stage_results = 0;
    int ro = 0;
    
    for (int rt = 0, ct = 0, i = 0; ro < rows_one; rt++) { //the loop shall be executed as long as we have not read the whole column
        //go through each column
        //after going through each row
        i++;
        //printf("rt : %d \n", rt);
        if (rt < rows_two) {
            //use this rt and ct to find the element
            stage_results += m[ro][rt] * n[rt][ct];
        } else if (rt == rows_two) {
            //append stage results to final results by using ro and ct
            final_results[ro][ct] = stage_results;
            stage_results = 0;
            //move to next column
            ct++;
            //rt should be reset to 0 so as to start from first row of this new column
            rt = 0;
            //dont forget to find element by this rt and ct

            if (ct == columns_two) {
            //printf("Fucking if\n");
            ct = 0;
            ro++;
            }

            stage_results += m[ro][rt] * n[rt][ct]; //NB
            //rt = -1;
            
        }
    }
        
    for (int r = 0, c = 0; r < rows_one; c++) {
        if (c < rows_one) {
            printf("%d ", final_results[r][c]);
        } else if (c == rows_one) {
            c = -1;
            r++;
            printf("\n");
        }
    }
    return 0;
}
