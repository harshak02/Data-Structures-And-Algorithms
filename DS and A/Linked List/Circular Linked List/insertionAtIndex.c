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

node * insertAtIndex(node * head,int data,int index){

    node *p;
    p = head;
    node *q;
    q = head;
    int i = 0;

    node *ptr;
    ptr = (node*)malloc(sizeof(node));

    q = q->next;

    while(i!=index-1){
        p = p->next;
        q = q->next;
        i++;
    }

    ptr->data = data;
    ptr->next = q;
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
    head = insertAtIndex(head,5,2);
    traversal(head);
    
    return 0;
}
