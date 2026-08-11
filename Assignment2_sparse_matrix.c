#include <stdio.h>

void show(int row, int column, int arr[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("\t%d", arr[i][j]);
        }
        printf("\n");
    }
}

void displaySparse(int k, int arr2[k][3])
{
    printf("\n\tRow\tColumn\tValue\n");

    for (int i = 0; i < k; i++)
    {
        printf("\t%d\t%d\t%d\n",
               arr2[i][0],
               arr2[i][1],
               arr2[i][2]);
    }
}

void simpleTranspose(int k, int arr2[k][3], int trans[k][3])
{
    int rows = arr2[0][0];
    int columns = arr2[0][1];
    int nonZero = arr2[0][2];

    // Header
    trans[0][0] = columns;
    trans[0][1] = rows;
    trans[0][2] = nonZero;

    int t = 1;

    // Check each column of original matrix
    for (int col = 0; col < columns; col++)
    {
        for (int i = 1; i <= nonZero; i++)
        {
            if (arr2[i][1] == col)
            {
                trans[t][0] = arr2[i][1];
                trans[t][1] = arr2[i][0];
                trans[t][2] = arr2[i][2];

                t++;
            }
        }
    }
}

void fastTranspose(int k, int arr2[k][3], int trans[k][3])
{
    int rows = arr2[0][0];
    int numCols = arr2[0][1];
    int numNonZero = arr2[0][2];

    // Header
    trans[0][0] = numCols;
    trans[0][1] = rows;
    trans[0][2] = numNonZero;

    int rowCount[numCols];
    int startPos[numCols];

    // Initialize rowCount
    for (int i = 0; i < numCols; i++)
    {
        rowCount[i] = 0;
    }

    // Count elements in each column
    for (int i = 1; i <= numNonZero; i++)
    {
        rowCount[arr2[i][1]]++;
    }

    // Calculate starting positions
    startPos[0] = 1;

    for (int i = 1; i < numCols; i++)
    {
        startPos[i] = startPos[i - 1] + rowCount[i - 1];
    }

    // Place elements in transposed matrix
    for (int i = 1; i <= numNonZero; i++)
    {
        int colIndex = arr2[i][1];

        int pos = startPos[colIndex];

        trans[pos][0] = arr2[i][1];
        trans[pos][1] = arr2[i][0];
        trans[pos][2] = arr2[i][2];

        startPos[colIndex]++;
    }
}

void menu()
{
    int row, column;

    printf("Enter the number of rows: ");
    scanf("%d", &row);

    printf("Enter the number of columns: ");
    scanf("%d", &column);

    int arr[row][column];

    printf("\nEnter the matrix values:\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter the value of (%d, %d): ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    show(row, column, arr);

    // Count non-zero elements
    int non_zero = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] != 0)
            {
                non_zero++;
            }
        }
    }

    // +1 for header row
    int k = non_zero + 1;

    int sparse[k][3];

    // Header
    sparse[0][0] = row;
    sparse[0][1] = column;
    sparse[0][2] = non_zero;

    // Store non-zero elements
    int idx = 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] != 0)
            {
                sparse[idx][0] = i;
                sparse[idx][1] = j;
                sparse[idx][2] = arr[i][j];

                idx++;
            }
        }
    }

    char choice;
    do{

    printf("\nEnter your choice:\n");
    printf("a. Display Sparse Matrix\n");
    printf("b. Simple Transpose\n");
    printf("c. Fast Transpose\n");
    printf("Choice: ");

    scanf(" %c", &choice);

    int trans[k][3];

    switch (choice)
    {
        case 'a':
            displaySparse(k, sparse);
            break;

        case 'b':
            simpleTranspose(k, sparse, trans);

            printf("\nSimple Transpose Sparse Matrix:\n");
            displaySparse(k, trans);
            break;

        case 'c':
            fastTranspose(k, sparse, trans);

            printf("\nFast Transpose Sparse Matrix:\n");
            displaySparse(k, trans);
            break;
         case 'd':
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }
}while (choice != 'd');
}

int main()
{
    menu();

    return 0;
}