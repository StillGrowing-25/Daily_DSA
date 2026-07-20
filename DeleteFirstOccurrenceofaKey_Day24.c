// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node*));
    if(!new){
        perror("Memory Allocation Failed");
        exit(-1);
    }
    new->value = data;
    new -> next = NULL;
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

void delete(int x,struct Node* head){
    struct Node* temp = head;
    struct Node* a = head;
    while(temp != NULL){
        if(temp->value == x){
            a->next = temp->next;
            free(temp);
            return;
        }
        a = temp;
        temp = temp->next;
    }
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
            tail = new;
        }
    }

    int x;
    printf("Enter the value of the key you wish to delete: ");
    scanf("%d",&x);

    delete(x,head);
    printList(head);

    struct Node* curr = head;
    while(curr!= NULL){
        struct Node* a = curr->next;
        free(curr);
        curr = a;
    }
}