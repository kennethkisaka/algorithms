#include <stdio.h>
#include <stdlib.h>

void clear_terminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#include <stdio.h>
#include <stdlib.h>

int calculate(int **m, int **n) {
    printf("CALCULATING...\n");
    //int m[2][3] = {{1,2,3},{4,5,6}};        //matrix 1
    //int n[3][2] = {{1,1},{2,2},{3,3}};        //matrix 2
    
    int *pointer = m[1];
    printf("%zu", pointer);
    printf("%zu", *m);
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

int** a_matrix() {
    //int *p; //shall return the address
    int co = 50,ro = 50;
    //getting number of rows and columns
    //int co = 0, ro = 0, ct = 0, rt = 0;
    printf("Matrix A\n");
    printf("Enter its rows: ");
    scanf("%d", &ro); // Added '&' before variables to pass their addresses
    printf("Enter its columns: "); // Fixed the format specifier
    scanf("%d", &co);
    printf("%d rows, %d columns\n", ro, co); // Added printing of ro and co for confirmation
    
    
    // Allocate memory for array of pointers (rows)
    int **arra = (int **)malloc(ro * sizeof(int *)); //allocating 50 rows for storing integer pointers.
    if (arra == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }

    // Allocate memory for each row
    for (int i = 0; i < ro; i++) {
        arra[i] = (int *)malloc(co * sizeof(int));
        if (arra[i] == NULL) {
            printf("Memory allocation failed.");
            return NULL;
        }
    }
    
    //taking the matrix
    printf("\nArray A (PRESS ENTER AFTER INSERTING A VALUE)\n(TO DELETE A VALUE TYPE '#' AND ENTER THE RIGHT VALUE)\n");
    for (int r = 0; r < ro; r++) { // Removed c from the initialization as it is always 0
        for (int c = 0; c < co; c++) { // Added loop for columns
            int z = 0; //shall hold the input 
            scanf("%d", &z); // nb-rm & Added '&' before a[r][c] to pass its address
            arra[r][c] = z;
        }
    }
    return arra;
}

int** b_matrix() {
    //int *p;
    int ct = 0, rt = 0;
    // Matrix B
    printf("\nMatrix B\n");
    printf("Enter its rows: ");
    scanf("%d", &rt);
    printf("Enter its columns: "); // Fixed the format specifier
    scanf("%d", &ct);
    printf("%d rows, %d columns\n", rt, ct); // Added printing of rt and ct for confirmation
    
    
    // Allocate memory for array of pointers (rows)
    int **arrb = (int **)malloc(rt * sizeof(int *)); //allocating 50 rows for storing integer pointers.
    if (arrb == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }

    // Allocate memory for each row
    for (int i = 0; i < rt; i++) {
        arrb[i] = (int *)malloc(ct * sizeof(int));
        if (arrb[i] == NULL) {
            printf("Memory allocation failed.");
            return NULL;
        }
    }
    
    printf("\nArray B (PRESS ENTER AFTER INSERTING A VALUE)\n(TO DELETE A VALUE TYPE '#' AND ENTER THE RIGHT VALUE)\n");
    for (int r = 0; r < rt; r++) { // Removed c from the initialization as it is always 0
        for (int c = 0; c < ct; c++) { // Added loop for columns
            int z = 0;
            scanf("%d", &z); //nb-rm &, Added '&' before a[r][c] to pass its address
            arrb[r][c] = z;
        }
    }
    
    //printing B for the user to see if it is correct.
    //printing MATRIX B
    printf("THIS MATRIX B \n");
    for (int r = 0, c = 0; r < rt; c++) {
        if (c < ct) {
            printf("%d ", arrb[r][c]);
        } else if (c == rt) {
            c = -1;
            r++;
            printf("\n");
        }
    }
    
    return arrb;
}



int main() { // Changed return type to void as the function doesn't return anything
    printf("MATRIX CALCULATOR (50 by 50)");
    //int a = a_matrix();
    //int b = b_matrix();
    int rows = 50, columns = 50;
    
    //Taking A and making sure user has entered correct matrix.
    int **pa; //pointer that stores address of a
    for (int i=1; i > 0; i++) {
        pa = a_matrix();
        //Asking for confirmation
        printf("\nCONFIRM THAT MATRIX A IS CORRECT\npress 0 if it is correct and any other number if not\n Enter number ");
        scanf("%d", &i);
        i--;
    }
    
    //int p_a = **pa;
    
    clear_terminal();
    
    //Taking B and Making sure user has entered correct matrix
    int **pb; //pointer that stores address of b
    for (int i=1; i > 0; i++) {
        pb = b_matrix();
        //Asking for confirmation
        printf("\nCONFIRM THAT MATRIX A IS CORRECT\npress 0 if it is correct and any other number if not\n Enter number ");
        scanf("%d", &i);
        i--;
    }
    
    //int p_b = **pb;
    
    calculate(pa, pb);
    
    printf("\n\n");
    
    return 0;
}
