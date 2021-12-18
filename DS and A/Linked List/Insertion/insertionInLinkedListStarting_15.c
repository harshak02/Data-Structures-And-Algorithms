#include<stdio.h> 
#include<stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
    
}node;

void traversal(node *ptr){

    while(ptr!= NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// void insertion(node *head,node *ins,int elem){

//     ins->data = elem;
//     ins->next = head;

// }

node* insertAtFirst(node *head,int data){

    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;

    return ptr;
}


int main(){

    // node *ins;
    // ins = (node*)malloc(sizeof(node));

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
    fourth->next = NULL;

    traversal(head);
    head = insertAtFirst(head,90);
    // traversal(ins);
    traversal(head);
    
    return 0;
}

// very very very important
// here we use ptr!=NULL if we didnt declared anything as node * ptr; ptr = head;
// other wise we use ptr->next!=NULL coz... we alderady pointed to the head node but in first we had
//not pointed
