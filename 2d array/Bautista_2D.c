#include<stdio.h>
#include<stdlib.h>
 
 
const int rows = 3;
const int cols = 3;
 
void printArray(double A[][cols]);
void printMenu();
void exer1(double A[][cols]);
void exer2(double A[][cols]);
void exer3(double A[][cols]);
int exer4(double A[][cols]);
void exer5(double A[][cols]);
double exer6(double A[][cols], int row_n);
double exer7(double A[][cols], int col_n);
void exer8(double A[][cols], double B[][cols], double C[][cols]);
 
 
int main() {
    double A[][3] = {{1,-3,5},{7,-9,-11},{-13,15,17}};
    double B[][3] = {{2,4,6},{8,10,12},{14,16,18}};
    double C[3][3];
 
    int choice;
    int row_n;
    int col_n;
 
    do {
        printMenu();
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Exercise 1 - Write a function that will initialize the contents of a double data type 2D array to 0.0.    Pass the array as parameter.\n");
                printf("--------------------------------------\n");
                exer1(A);
                break;
            case 2:
                printf("Exercise 2 - Same as the problem above, but allow the user to input the value of the array element via scanf() statement.\n");
                printf("--------------------------------------\n");
                exer2(A);
                break;
            case 3:
                printf("Exercise 3 - Write a function that will display all the elements of the 2D array.    Elements should be printed starting from the first row up to the last row, and from the first column to the last column within the same row.    Elements of the same row should be printed on the same line separated by two spaces.    Pass the array as parameter.\n");
                printf("--------------------------------------\n");
                exer3(A);
                break;
            case 4:
                printf("Exercise 4 - Write a function that will return the number of negative elements inthe 2D array.    Pass the array as parameter.\n");
                printf("--------------------------------------\n");
                printf("Number of negative elements is %d.\n", exer4(A));
                break;
            case 5:
                printf("Exercise 5 - Write a function that will print only the elements on the main diagonal of the 2D array.      Pass the array as parameter.\n");
                printf("--------------------------------------\n");
                exer5(A);
                break;
            case 6:
                printf("Exercise 6 - Write a function that will return the sum of the elements on a specified row.        Pass the array    and the row as parameters.\n");
                printf("--------------------------------------\n");
                printf("Choose a row number: ");
                scanf("%d", &row_n);
                printf("Sum of elements in row %d is %lf.\n", row_n, exer6(A, row_n));
                break; 
               case 7:
               printf("Exercise 7 - Write a function that will    return the sum of the elements on a specified column.    Pass the array and the column as parameters.\n");
                printf("--------------------------------------\n");
                printf("Choose a column number: ");
                scanf("%d", &col_n);
                printf("Sum of elements in column %d is %lf.\n", col_n, exer6(A, col_n));        
               break;
            case 8:
                printf("Exercise 8 - Assume three matrices of the same size, say matrix A, B and C.    Write a function that will add the two matrices A and B and store the sum to C.    Matrix addition is done component-wise, i.e., C[i    ,j] = A[i, j] + B[i, j] where i, j are the row and column index respectively.    Pass the three arrays as parameters.\n");
                printf("--------------------------------------\n");
                exer8(A, B, C);
                break;
            case 9:
                printf("Exiting Program...\n");
                exit (0);	
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 9);
 
    return 0;
}
 
void printArray(double A[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.1f\t", A[i][j]);
        }
        printf("\n");
    }
}

void printMenu() {
    printf("--------------------------------------\n");
    printf("[1] Exercise 1\n");
    printf("[2] Exercise 2\n");
    printf("[3] Exercise 3\n");
    printf("[4] Exercise 4\n");
    printf("[5] Exercise 5\n");
    printf("[6] Exercise 6\n");
    printf("[7] Exercise 7\n");
    printf("[8] Exercise 8\n");
    printf("[9] Exit\n");
    printf("--------------------------------------\n");
    printf("Choose an Exercise: ");
}
 
void exer1(double A[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = 0.0;
        }
    }
    printArray(A);
}
 
void exer2(double A[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Input value for A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    printArray(A);
}
 
void exer3(double A[][cols])
{
    printArray(A);
}
 
int exer4(double A[][cols]) {
    int neg = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] < 0)
            {
                neg += 1;
            }
        }
    }
    return neg;
}
 
void exer5(double A[][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("%.1f ", A[i][i]);
    }
    printf("\n");
}
 
double exer6(double A[][cols], int row_n) {
    double sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += A[row_n][j];
        }
    return sum;
}
 
double exer7(double A[][cols], int col_n) {
    double sum = 0;
    for (int i = 0; i < rows; i++) {
            sum += A[i][col_n];
    }
    return sum;
}
 
void exer8(double A[][cols], double B[][cols], double C[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }\
    printArray(A);
    printf("+\n");
    printArray(B);
    printf("=\n");
    printArray(C); 
}