/*Write a program that finds the maximum and minimum elements of a two-dimensional
array. Use an array version and a pointer version.*/
#include <stdio.h>

void arr();
void ptr();

int main() 
{
    arr();
    ptr();

    return 0;
}

void arr() {
    int arr[10][10];
    int rows, cols, i, j;
    int max, min;
    printf("\tArray Version\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the elements of the array: \n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("Arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    max = min = arr[0][0];

    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            if(arr[i][j] > max)
            {
                max = arr[i][j];
            }
            if(arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }

    printf("\nMinimum element = %d\n", min);
    printf("Maximum element = %d\n", max);
}

void ptr()
{
    int rows, cols, i, j;
    int max, min;

    printf("\n\tPointer Version\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **numArr = (int **)malloc(rows * sizeof(int *));

    for (i = 0; i < rows; i++)
    {
        numArr[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("\nEnter the elements of the array: \n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("ptrArr[%d][%d]: ", i, j);
            scanf("%d", (*(numArr + i) + j));
        }
    }

    max = min = *(*(numArr + 0) + 0);

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (*(*(numArr + i) + j) > max)
            {
                max = *(*(numArr + i) + j);
            }
            if (*(*(numArr + i) + j) < min)
            {
                min = *(*(numArr + i) + j);
            }
        }
    }

    printf("\nMinimum element = %d\n", min);
    printf("Maximum element = %d\n", max);
}