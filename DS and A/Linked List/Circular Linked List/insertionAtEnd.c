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

// node * insertAtEnd(node * head,int data){

//     node *p;
//     p = head;
//     node *q;
//     q = head;

//     node *ptr;
//     ptr = (node*)malloc(sizeof(node));

//     q = q->next;

//     while(p->next!=head){
//         p = p->next;
//         q = q->next;
//     }

//     ptr->data = data;
//     ptr->next = q;
//     p->next = ptr;

//     return head;
// }


//crct
node *insertAtEnd(node *head,int val){

    node *ptr = head;

    node * ins_node;
    ins_node = (node*)malloc(sizeof(node));

    while(ptr->next!=head){
        ptr = ptr->next;
    }

    ins_node->data = val;
    ptr->next = ins_node;
    ins_node->next = head;

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
    head = insertAtEnd(head,5);
    traversal(head);
    
    return 0;
}
