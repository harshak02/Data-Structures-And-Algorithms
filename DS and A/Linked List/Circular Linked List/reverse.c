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
}

node * reverse(node *head){

    node* temp=head;
    node* prev=head;
    node* current=head;
    current=current->next;
    temp=temp->next->next;
    while(current!=head){
        current->next=prev;
        prev=current;
        current=temp;
        temp=temp->next;
    }
    head=prev;
    current->next=head;

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
    printf("\n");

    head = reverse(head);
    traversal(head);
    
    return 0;
}
