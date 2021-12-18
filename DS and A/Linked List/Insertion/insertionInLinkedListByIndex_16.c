#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node{

    int data;
    struct Node *next;
}node;

void traversal(node *head){
    node *ptr;
    ptr = head;
    int i = 0;

    while(ptr!=NULL){
        printf("The %d element is %d\n",i+1,ptr->data);
        ptr = ptr->next;
        i++;
    }

}

node * insertAtIndex(node *head,int data,int index){

    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    node *p;
    p = head;

    for(int i = 0;i<index-1;i++){
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
    head = insertAtIndex(head,45,3);
    traversal(head);

    
    return 0;
}
