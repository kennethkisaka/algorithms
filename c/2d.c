#include <stdio.h>
#include <stdlib.h>

void clear_terminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
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
    int *pa; //pointer that stores address of a
    for (int i=1; i > 0; i++) {
        int **pa = a_matrix();
        //Asking for confirmation
        printf("\nCONFIRM THAT MATRIX A IS CORRECT\npress 0 if it is correct and any other number if not\n Enter number ");
        scanf("%d", &i);
        i--;
    }
    
    clear_terminal();
    
    //Taking B and Making sure user has entered correct matrix
    int *pb; //pointer that stores address of b
    for (int i=1; i > 0; i++) {
        int **pb = b_matrix();
        //Asking for confirmation
        printf("\nCONFIRM THAT MATRIX A IS CORRECT\npress 0 if it is correct and any other number if not\n Enter number ");
        scanf("%d", &i);
        i--;
    }
    
    printf("\n\n");
    
    return 0;
}
