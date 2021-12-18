#include<stdio.h> 
#include<stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    
}node;

node *head = NULL;

void traversal(node *ptr){

    while(ptr!= NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

void reverse(){

    node * curr = head;
    node * prev = NULL;
    node * frwd;

    while(curr!=NULL){

        frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
    }

    head = prev;//declaring new head
}

node *reverseUsingRec(node * head){

    node *ptr = head;

    if(ptr==NULL || ptr->next==NULL){
        return ptr;
    }

    node *newHead = reverseUsingRec(ptr->next);

    ptr->next->next = ptr;
    ptr->next = NULL;

    return newHead;
}

int main(){

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
