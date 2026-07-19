// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct Node* createNode(int data ){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node* ));
        newNode-> value = data;
        newNode->next = NULL;
        return newNode;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->value);
        temp = temp -> next;
    }printf("NULL");
}

struct Node* merge(struct Node* a, struct Node* b){
    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* temp1 = a;
    struct Node* temp2 = b;
    struct Node* new;
    while(temp1 != NULL && temp2!= NULL){
        if(temp1->value<temp2->value){
            new = createNode(temp1->value);
            temp1 = temp1->next;
            
        }else{
            new = createNode(temp2->value);
            temp2 = temp2->next;
        }
        if(head == NULL){
            head = tail =new; 
        }else{
            tail->next = new;
            tail = new;
        }
    }
    while(temp1 != NULL){
        new = createNode(temp1->value);
        if(head == NULL){
            head = tail =new; 
        }else{
            tail->next = new;
            tail = new;
        }
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        new = createNode(temp2->value);
        if(head == NULL){
            head = tail =new; 
        }else{
            tail->next = new;
            tail = new;
        }
        temp2 = temp2->next;
    }
    return head;
}
int main(){
    int n, m, value; 
    printf("Enter the number of elememts in list 1: ");
    scanf("%d",&n);
    
    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;
    printf("Enter the elements in sorted order in list 1: \n");
    for(int i =0; i<n; i++){
        scanf("%d",&value);
        struct Node* new = createNode(value);

        if(head1 == NULL){
            head1 = tail1 = new;
        }else{
            tail1->next = new;
            tail1 = new;
        }
    }

    printf("Enter the number of elements in list 2: ");
    scanf("%d",&m);

    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;
    printf("Enter the elements in sorted order in list 2: \n");
    for(int i =0; i<m; i++){
        scanf("%d",&value);
        struct Node* new = createNode(value);

        if(head2 == NULL){
            head2 = tail2 = new;
        }else{
            tail2->next = new;
            tail2 = new;
        }
    }

    
    struct Node* head = merge(head1,head2);
    printf("The merged list is: ");
    printList(head);

     struct Node* current1 = head1;
    while(current1 != NULL){
        struct Node* next = current1->next;
        free(current1);
        current1 = next;
    }

     struct Node* current2 = head2;
    while(current2 != NULL){
        struct Node* next = current2->next;
        free(current2);
        current2 = next;
    }

     struct Node* current = head;
    while(current != NULL){
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}