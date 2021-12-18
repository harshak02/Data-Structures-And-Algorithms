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

node * insertAtEnd(node *head,int data){

    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    node *p;
    p = head;

    while(p->next!=NULL){
        p = p->next;
    }

    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;

    return head;
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
    head = insertAtEnd(head,90);
    traversal(head);
    
    return 0;
}
