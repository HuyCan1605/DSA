#include <stdio.h>

void function(int arr[], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int temp = i * cols + j;
            printf("%d ", arr[temp]);
        }
        printf("\n");
    }
}

int main() {
    int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int rows = 3, cols = 3;
    
    function((int *)arr, rows, cols);
    
    return 0;
}