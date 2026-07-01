// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

// Input:
// - First line: integer n (array size)
// - Second line: n space-separated integers
// - Third line: integer k (key to search)

// Output:
// - Line 1: "Found at index i" OR "Not Found"
// Line 2: "Comparisons = c"

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// Found at index 2
// Comparisons = 3

// Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
#include <stdio.h>

int main() {
    int n, x, c = 0, pos = -1;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    for(int i = 0; i < n; i++) {
        c++;

        if(arr[i] == x) {
            pos = i;
            break;
        }
    }

    if(pos == -1)
        printf("Not Found");
    else
        printf("Found at index %d", pos);

    printf("\nComparisons = %d", c);

    return 0;
}
