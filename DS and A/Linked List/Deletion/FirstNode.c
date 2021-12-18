#include<stdio.h> 
#include<stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    
}node;

void traversal(node *ptr){

    while(ptr!= NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

node * deleteFirst(node * head){
    node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 1: Deleting the first element from the linked list
// node * deleteFirst(node * head){
//     node * ptr = head;
//     head = head->next;
//     free(ptr);
//     return head;
// }


int main(){

    node *head;
    head = (node*)malloc(sizeof(node));

    node *second;
    second = (node*)malloc(sizeof(node));

    node *third;
    third = (node*)malloc(sizeof(node));

    node *fourth;
    fourth = (node*)malloc(sizeof(node));

    node *fifth;
    fifth = (node*)malloc(sizeof(node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    traversal(head);
    head = deleteFirst(head);
    traversal(head);
    
    return 0;
}
