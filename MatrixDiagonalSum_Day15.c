// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 15

// Explanation:
// 1 + 5 + 9 = 15
#include <stdio.h>
int main()
{
    int r, c,sum =0;
    printf("Enter the number of rows and columns: \n");
    scanf("%d %d", &r, &c);

    int arr[r][c];
    printf("Enter the elements in matrix.\n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("Enter value for matrix_1 row=%d col=%d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (i == j) 
            sum+=arr[i][j];
            }
        }
    printf("%d",sum);
    return 0;
}
