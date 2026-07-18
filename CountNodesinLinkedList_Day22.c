// Problem: Count Nodes in Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int main(){

    int n, value;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++){

        scanf("%d", &value);
        struct Node *new = createNode(value);

        if (head == NULL){
            head = tail = new;
        }
        else{
            tail->next = new;
            tail = new;
        }
    }
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL){
        count ++;
        temp = temp->next;
    }

    printf("\nThe number of nodes are %d.",count);

    struct Node* current = head;
    while(current != NULL){
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}