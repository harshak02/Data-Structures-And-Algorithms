#include<stdio.h> 
#include<stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    
}node;

void traversal(node *head){

    node* ptr;
    ptr = head;

    while(ptr!= NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

// node * rearrange(node * head){

//     node * ptr = head;
//     node *ptre;
//     ptre = head->next;
//     node *temp = ptre;

//     while(ptr->next!=NULL && ptre->next!=NULL){

//         ptr->next = ptre->next;
//         ptr = ptr->next;
//         ptre->next = ptr->next;
//         ptre = ptre->next;
//     }

//     if(ptre->next==NULL){
//         ptr->next = temp;
//     }

//     else{
//         ptr->next = temp;
//         ptre->next = NULL;
//     }

//     return head;

// }

void rearrange(node * head){

    node *ptre;
    ptre = head->next;
    node *temp = ptre;

    while(head->next!=NULL && ptre->next!=NULL){

        head->next = ptre->next;
        head = head->next;
        ptre->next = head->next;
        ptre = ptre->next;
    }

    if(ptre->next==NULL){
        head->next = temp;
    }

    else{
        head->next = temp;
        ptre->next = NULL;
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

    node *fifth;
    fifth = (node*)malloc(sizeof(node));

    node *sixth;
    sixth = (node*)malloc(sizeof(node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = NULL;

    traversal(head);
    rearrange(head);
    traversal(head);
    
    return 0;
}
