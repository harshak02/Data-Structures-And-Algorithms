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

node * insertAfterKey(node *head,int data,int elem){

    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->data = elem;
    node *p;
    p = head;

    while(1){
        if(p->data==data){
            break;
        }
        p = p->next;
    }

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
    head = insertAfterKey(head,30,100);
    traversal(head);
    
    return 0;
}
