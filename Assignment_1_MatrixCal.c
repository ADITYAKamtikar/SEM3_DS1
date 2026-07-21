#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols)
{
    int sum[MAX][MAX];
    int i, j;

    printf("\nResult of Addition:\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void subtractMatrix(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols)
{
    int sub[MAX][MAX];
    int i, j;

    printf("\nResult of Subtraction:\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
}


void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int r2, int c2)
{
    int mul[MAX][MAX];
    int i, j, k;

    printf("\nResult of Multiplication:\n");

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            mul[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                mul[i][j] = mul[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }

    printf("\nResult of Multiplication:\n");
    displayMatrix(mul, r1, c2);
}

void transposeMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < cols; i++)
    {
        for(j = 0; j < rows; j++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}



int main()
{
    int matrix1[MAX][MAX], matrix2[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("Enter rows and columns of Matrix 1: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix 1:\n");
    inputMatrix(matrix1, r1, c1);

    printf("Enter rows and columns of Matrix 2: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix 2:\n");
    inputMatrix(matrix2, r2, c2);

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose of Matrix 1\n");
        printf("5. Transpose of Matrix 2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(r1 == r2 && c1 == c2)
                    addMatrix(matrix1, matrix2, r1, c1);
                else
                    printf("Addition not possible! Matrices must have same dimensions.\n");
                break;

            case 2:
                if(r1 == r2 && c1 == c2)
                    subtractMatrix(matrix1, matrix2, r1, c1);
                else
                    printf("Subtraction not possible! Matrices must have same dimensions.\n");
                break;

            case 3:
                if(c1 == r2)
                    multiplyMatrix(matrix1, matrix2, r1, c1, r2, c2);
                else
                    printf("Multiplication not possible! Columns of Matrix1 must equal rows of Matrix2.\n");
                break;

            case 4:
                printf("\nTranspose of Matrix 1:\n");
                transposeMatrix(matrix1, r1, c1);
                break;

            case 5:
                printf("\nTranspose of Matrix 2:\n");
                transposeMatrix(matrix2, r2, c2);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}


