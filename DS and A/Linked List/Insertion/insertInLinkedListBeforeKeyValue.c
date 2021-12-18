#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node{

    int data;
    struct Node *next;
}node;

void traversal(node *ptr){

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

node * insertBeforeKey(node *head,int data,int elem){

    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->data = elem;
    node *p;
    p = head;
    node *q;
    q = head;

    p = p->next;

    while(p->data!=data){
        p = p->next;
        q = q->next;
    }

    ptr->next = q->next;
    q->next = ptr;

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

    node *fifth;
    fifth = (node*)malloc(sizeof(node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    int key;
    key = 30;

    traversal(head);
    head = insertBeforeKey(head,30,100);
    traversal(head);
    
    return 0;
}
