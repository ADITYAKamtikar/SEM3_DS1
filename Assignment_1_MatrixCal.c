#include <stdio.h>

void add(int row, int column, int arr1[row][column], int arr2[row][column], int arr3[row][column]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void subtract(int row, int column, int arr1[row][column], int arr2[row][column], int arr3[row][column]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            arr3[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

void multiply(int r1, int c1, int r2, int c2, int arr1[r1][c1], int arr2[r2][c2], int arr3[r1][c2]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            arr3[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void transpose(int row, int column, int arr[row][column], int arr3[column][row]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            arr3[j][i] = arr[i][j];
        }
    }
}

void show(int row, int column, int arr[row][column]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void menu(int row1, int column1, int row2, int column2, int arr1[row1][column1], int arr2[row2][column2]) {
    char choice;
    do{
    printf("Enter your choice :\n");
    printf("a. Add both matrices\n");
    printf("b. Subtract both matrices\n");
    printf("c. Multiply the matrices\n");
    printf("d. Take the transpose of Matrix 1\n");
    printf("Choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'a':
            if (row1 == row2 && column1 == column2) {
                int arr3[row1][column1];
                add(row1, column1, arr1, arr2, arr3);
                printf("Resultant Matrix:\n");
                show(row1, column1, arr3);
            } else {
                printf("Addition requires same dimensions.\n");
            }
            break;
        case 'b':
            if (row1 == row2 && column1 == column2) {
                int arr3[row1][column1];
                subtract(row1, column1, arr1, arr2, arr3);
                printf("Resultant Matrix:\n");
                show(row1, column1, arr3);
            } else {
                printf("Subtraction requires same dimensions.\n");
            }
            break;
        case 'c':
            if (column1 == row2) {
                int arr3[row1][column2];
                multiply(row1, column1, row2, column2, arr1, arr2, arr3);
                printf("Resultant Matrix:\n");
                show(row1, column2, arr3);
            } else {
                printf("Multiplication requires column of 1st equal to row of 2nd.\n");
            }
            break;
        case 'd': {
            int arr3[column1][row1];
            transpose(row1, column1, arr1, arr3);
            printf("Resultant Transpose Matrix:\n");
            show(column1, row1, arr3);
            break;
        }
        case 'e':{
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }
}while(choice!='e');
}

void input(int row1, int column1, int row2, int column2) {
    int arr1[row1][column1];
    int arr2[row2][column2];

    printf("Enter elements for 1st matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column1; j++) {
            printf("arr1[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements for 2nd matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < column2; j++) {
            printf("arr2[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr2[i][j]);
        }
    }

    menu(row1, column1, row2, column2, arr1, arr2);
}

int main() {
    int row1, row2, column1, column2;

    printf("Enter the no. of Rows for 1st matrix: ");
    scanf("%d", &row1);
    printf("Enter the no. of Columns for 1st matrix: ");
    scanf("%d", &column1);

    printf("Enter the no. of Rows for 2nd matrix: ");
    scanf("%d", &row2);
    printf("Enter the no. of Columns for 2nd matrix: ");
    scanf("%d", &column2);

    input(row1, column1, row2, column2);

    return 0;
}