// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer pos (1-based position to delete)

// Output:
// - Print the updated array with (n-1) elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 10 30 40 50

// Explanation: Delete position 2 (element 20), remaining elements shift left
#include <stdio.h>

int main()
{
    int n, pos, p;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the position (1-based) where you want to delete the element: ");
    scanf("%d", &pos);

    for (int j = pos - 1; j < n - 1; j++){
        arr[j] = arr[j + 1];
    }

    printf("Updated array: ");
    for (int i = 0; i < n - 1; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}