// Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the linked list elements in forward order, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node*));
    if(!new){
        perror("Memory Allocation Failed");
        exit(-1);
    }
    new->value = data;
    new -> next = NULL;
    new->prev = NULL;
    return new;

}

void printList(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->value);
        temp = temp-> next;
    }
    printf("NULL");
}

int main(){
    int n,value;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    struct Node* head =  NULL;
    struct Node* tail = NULL;

    printf("Enter the value of elements: \n");
    for(int i =0; i<n; i++){
        scanf("%d",&value);
        struct Node* new = createNode(value);

        if(head == NULL){
            head = tail = new;
        }else{
            tail->next = new;
            new->prev = tail;
            tail = new;
        }
    }
    
    printList(head);

    struct Node* curr = head;
    while(curr!= NULL){
        struct Node* a = curr->next;
        free(curr);
        curr = a;
    }
}