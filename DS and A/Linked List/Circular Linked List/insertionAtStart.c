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

// node * insertAtFirst(node * head,int data){

//     node *ptr;
//     ptr = (node*)malloc(sizeof(node));
//     ptr->data = data;

//     node *p;
//     p = head;

//     p = p->next;

//     while(p->next !=head){
//         p = p->next;
//     }

//     ptr->next = head;
//     p->next = ptr;
//     head = ptr;

//     return head;
// }


//recent one
node * insertAtFirst(node * head,int val){

    node * ptr = head;

    node * ins_node;
    ins_node = (node*)malloc(sizeof(node));
    ins_node->data = val;
    ins_node->next = head;

    while(ptr->next!=head){
        ptr = ptr->next;
    }

    ptr->next = ins_node;
    head = ins_node;

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
    head = insertAtFirst(head,5);
    traversal(head);
    
    return 0;
}
