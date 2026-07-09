// Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the matrix

// Output:
// - Print "Symmetric Matrix" if the given matrix is symmetric
// - Otherwise, print "Not a Symmetric Matrix"

// Example:
// Input:
// 3 3
// 1 2 3
// 2 4 5
// 3 5 6

// Output:
// Symmetric Matrix

// Explanation:
// The matrix is square (3 × 3) and for every i and j, element[i][j] = element[j][i].

// Test Cases:

// Test Case 1:
// Input:
// 2 2
// 1 2
// 2 1
// Output:
// Symmetric Matrix

// Test Case 2:
// Input:
// 3 3
// 1 0 1
// 2 3 4
// 1 4 5
// Output:
// Not a Symmetric Matrix

// Test Case 3:
// Input:
// 2 3
// 1 2 3
// 4 5 6
// Output:
// Not a Symmetric Matrix

#include <stdio.h>
int main()
{
    int r, c;
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
    int i, j, flag = 1;
    if (r == c){
        for (i = 0; i < r; i++){
            for (j = 0; j < c; j++){
                if (arr[j][i] != arr[i][j]){
                    flag = 0;
                }
            }
        }
    }else{
        flag = 0;
    }

    if(flag == 0){
        printf("Not a symmetric matrix.");
    }else{
        printf("Yes a symmetric matrix.");
    }
}