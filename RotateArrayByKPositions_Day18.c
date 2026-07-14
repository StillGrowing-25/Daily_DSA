// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3
#include <stdio.h>

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], ans[n];  

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d",&k);

    
    for(int i =0, j=0; i<n;i++){
        if(k > 0){
            ans[i] = arr[n-k];
            k--;
        } else{
            ans[i]= arr[j];
            j++;
        }
    }
    printf("Rotated Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}