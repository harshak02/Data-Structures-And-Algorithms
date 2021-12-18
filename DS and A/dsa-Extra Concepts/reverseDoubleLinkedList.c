#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node{

    struct Node *prev;
    int data;
    struct Node *next;

}node;


void frontThenReverse(struct Node *ptr)
{
    while (ptr->next!= NULL)
    {
        printf("%d  ",ptr->data);
        ptr = ptr->next;
    }

    printf("%d  ",ptr->data);
 
}

node * reverse(node * head){

    node * temp = NULL;
    node * current = head;

    while(current!=NULL){

        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp!=NULL){

        head = temp->prev;

    }

    return head;

}

// node * reverse(node *head_ref)  
// {  
//     node *temp = NULL;  
//     node *current = head_ref;  
      
//     /* swap next and prev for all nodes of  
//     doubly linked list */
//     while (current != NULL)  
//     {  
//         temp = current->prev;  
//         current->prev = current->next;  
//         current->next = temp;              
//         current = current->prev;  
//     }  
      
//     /* Before changing head, check for the cases like empty  
//         list and list with only one node */
//     if(temp != NULL )  
//         head_ref = temp->prev; 

//     return head_ref; 
// }  

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
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = fourth;

    fourth->data = 4;
    fourth->prev = third;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->prev = fourth;
    fifth->next = NULL;

    frontThenReverse(head);
    printf("\n");

    head = reverse(head);
    frontThenReverse(head);

    
    return 0;
}
