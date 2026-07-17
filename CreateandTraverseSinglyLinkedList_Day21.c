// Problem: Create and Traverse Singly Linked List

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
#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int value;
    struct Node* next;
};

void display(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->value);
        temp = temp->next;
    }
    printf("NULL");
}

int main(){

    int n,value;
    printf("Enter the number of elements you wish to enter: ");
    scanf("%d",&n);
    if(n<=0)
    return 0;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter the elements: \n");
    for(int i =0; i<n; i++){
        scanf("%d",&value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = value;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
        printf("Traversing the linked list: ");
        display(head);

        struct Node* current = head;
        while(current != NULL){
            struct Node* nextNode = current->next;
            free(current);
            current = nextNode;
        }
        return 0;
}