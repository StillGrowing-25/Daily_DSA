// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];  

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    int left = 0;
    int right = n - 1;
    int min_sum = INT_MAX;
    int a = 0, b = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        // Check if this pair is closer to zero
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            a = arr[left];
            b = arr[right];
        }

        // Move pointers based on the sum value
        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            break; // Found an exact sum of 0
        }
    }

    printf("\n The pair is %d %d\n", a, b);

    free(arr);
    return 0;
}