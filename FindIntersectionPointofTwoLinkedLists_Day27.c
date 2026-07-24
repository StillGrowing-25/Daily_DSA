// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to calculate the length of a linked list
int getLength(struct Node* head) {
    int len = 0;

    while (head != NULL) {
        len++;
        head = head->next;
    }

    return len;
}

// Function to find the intersection node
struct Node* findIntersection(struct Node* head1, struct Node* head2) {

    // Step 1: Find lengths of both linked lists
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Step 2: Initialize pointers
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Step 3: Move the pointer of the longer list
    if (len1 > len2) {
        int diff = len1 - len2;

        while (diff--) {
            ptr1 = ptr1->next;
        }
    }
    else {
        int diff = len2 - len1;

        while (diff--) {
            ptr2 = ptr2->next;
        }
    }

    // Step 4: Move both pointers together
    while (ptr1 != NULL && ptr2 != NULL) {

        // Compare node addresses
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {

    // Create common part
    struct Node* common = createNode(40);
    common->next = createNode(50);
    common->next->next = createNode(60);

    // First Linked List
    struct Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = createNode(30);
    head1->next->next->next = common;

    // Second Linked List
    struct Node* head2 = createNode(15);
    head2->next = common;

    // Find intersection
    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("Intersection Node = %d\n", intersection->data);
    else
        printf("No Intersection Found\n");

    return 0;
}