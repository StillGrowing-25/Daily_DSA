// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum elements

// Example:
// Input:
// 6
// 3 5 1 9 2 8

// Output:
// Max: 9
// Min: 1

#include <stdio.h>
#include<climits>

int main() {
    int n,max = INT_MIN, min = INT_MAX;

    printf("Enter number of elements: ");
    scanf("%d", &n); 

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        max = (arr[i]>max?arr[i]:max);
        min = (arr[i]<min?arr[i]:min);
    }

    printf("Maximum: %d \nMinimum: %d",max,min);
    return 0;
}