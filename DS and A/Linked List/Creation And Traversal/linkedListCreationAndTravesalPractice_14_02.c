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
}

int main(){

    node *head;
    head = (node*)malloc(sizeof(node));

    node *second;
    second = (node*)malloc(sizeof(node));

    node *third;
    third = (node*)malloc(sizeof(node));

    node *fourth;
    fourth = (node*)malloc(sizeof(node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    traversal(head);

    reverse();
    printf("\n");
    traversal(head);
    
    head = reverseUsingRec(head);
    printf("\n");
    traversal(head);
    
    return 0;
}
