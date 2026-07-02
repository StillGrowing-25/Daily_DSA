// Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (sorted array)

// Output:
// - Print unique elements only, space-separated

// Example:
// Input:
// 6
// 1 1 2 2 3 3

// Output:
// 1 2 3

// Explanation: Keep first occurrence of each element: 1, 2, 3

#include <stdio.h>

int main()
{
    int n, pos, x, p;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    int arr[n + 1];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

   int uniqueCount = 0;
   for (int i = 0; i < n; i++) {
       if (i == 0 || arr[i] != arr[i - 1]) {
           arr[uniqueCount++] = arr[i];
       }
   }

   printf("Unique elements: ");
   for (int i = 0; i < uniqueCount; i++) {
       printf("%d ", arr[i]);
   }

   return 0;
}