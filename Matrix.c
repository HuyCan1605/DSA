#include <stdio.h>
#include <stdbool.h>

void traversal_matrix(int arr[], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; ++i)
    {
        for (j = 0; j < cols; ++j)
        {
            printf("%d ", arr[i*rows + j]);
        }
        printf("\n");
    }
}

bool searching_in_matrix(int arr[][3], int n, int key)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (key == arr[i][j])
                return true;
        }
    }
    return false;
}

void swap_Element(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
/*
Given a square matrix, the task is that we turn it by 180 degrees in an anti-clockwise direction
without using any extra space.
Input :  1  2  3
         4  5  6
         7  8  9
Output : 9 8 7
         6 5 4
         3 2 1
Input :  1 2 3 4
         5 6 7 8
         9 0 1 2
         3 4 5 6
Output : 6 5 4 3
         2 1 0 9
         8 7 6 5
         4 3 2 1
*/
void rotate_matrix_180(int arr[3][3], int len)
{
    int i, j, m, n, count;
    i = 0, j = 0, m = len - 1, n = len - 1, count = 0;
    int temp = len * len / 2;
    for (i = 0; count < temp; ++i)
    {
        for (j = 0; j < len && count < temp; ++j)
        {
            count++;
            swap_Element(&arr[i][j], &arr[len - i - 1][len - j - 1]);
        }
    }
}

/* Transpose matrix is that  each row of the given matrix becomes a column of  the transposed matrix and vice versa
Let the given matrix be
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

First we find transpose.
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16*/

void transpose_matrix(int arr[][], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; ++i)
    {
        for (j = 0; j < cols; ++j)
        {
            if (i != j)
                swap_Element(&arr[i][j], &arr[j][i]);
        }
    }
}
/*Print the Principal and Secondary diagonals.
Input:
4
1 2 3 4
4 3 2 1
7 8 9 6
6 5 4 3
Output:
Principal Diagonal: 1, 3, 9, 3
Secondary Diagonal: 4, 2, 8, 6
*/

void print_principal_diagonals(int arr[][], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        printf(" %d", arr[i][i]);
    }
}

void print_second_diagonals(int arr[][4], int rows, int cols)
{
    for (int i = cols; i > 0; --i)
    {
            printf("%d ", arr[rows - i - 1][i]);
    }
}

void main()
{

    // Declaration  of variables
    // Defining number of rows and columns in matrix
    int number_of_rows = 3, number_of_column = 3;
    int arr[number_of_rows][number_of_column];

    // Initializing Matrix
    int arr2[4][4] =
        {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 10, 11, 12},
         {13, 14, 15, 16}};

    int arr[3][3] = 
    {{1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};
    print_second_diagonals(arr2, 4, 4);
    // printf("Orginal matrix: \n");
    // traversal_matrix((int *)arr, number_of_rows, number_of_rows);
    // rotate_matrix_180(arr3, len);
    // printf("After matrix: \n");
    // traversal_matrix(arr3,len);
}