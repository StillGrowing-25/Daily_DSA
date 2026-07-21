// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20

// Output:
// 3

// Explanation:
// Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.
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

int countOcc(int x, struct Node* head){
    struct Node* temp = head;
    int count = 0;
    while(temp != NULL){
        if(temp->value == x)
        count++;
        temp = temp->next;
    }return count;
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
    printf("Enter the value of the key you wish to count: ");
    scanf("%d",&x);

    x = countOcc(x,head);
    printf("%d",x);

    struct Node* curr = head;
    while(curr!= NULL){
        struct Node* a = curr->next;
        free(curr);
        curr = a;
    }
}