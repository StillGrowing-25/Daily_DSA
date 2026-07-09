// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards
#include <stdio.h>
#include <string.h> // Required for strlen

int main()
{
    char s[1000] = "";
    int flag = 1;

    printf("Enter the string: ");
    scanf("%999s", s);

    int len = strlen(s);
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            printf("NO");
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        printf("YES");
    return 0;
}