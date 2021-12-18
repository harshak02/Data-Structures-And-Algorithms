#include<stdio.h> 
#include<stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    
}node;

// void traversal(node *ptr){

//     node *p = ptr;

//     do{
    
//         printf("%d ",ptr->data);
//         ptr = ptr->next;
//     }while(ptr!= p);

// }

void traversal(node * head){

    node *ptr = head;
    printf("%d ",ptr->data);

    ptr = ptr->next;

    while(ptr!=head){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
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
    
    return 0;
}
