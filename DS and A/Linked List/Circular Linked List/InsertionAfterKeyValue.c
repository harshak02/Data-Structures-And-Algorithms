#include<stdio.h> 
#include<stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    
}node;

void traversal(node *head){

    node *ptr;
    ptr = head;

    while(ptr->next!= head){// points but one node
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

    printf("%d",ptr->data);
    printf("\n");
}

node * insertAfterKey(node * head,int data,int key){

    node *p;
    p = head;

    node *ptr;
    ptr = (node*)malloc(sizeof(node));

    while(p->data!=key){
        p = p->next;
    }

    ptr->data = data;
    ptr->next = p->next;
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
    fourth->next = head;

    traversal(head);
    head = insertAfterKey(head,5,2);
    traversal(head);
    
    return 0;
}
