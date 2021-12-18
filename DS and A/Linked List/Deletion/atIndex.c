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

// node * delete(node * head,int index){

//     node * p = head;
//     node * q = head;

//     q = q->next;
//     q = q->next;

//     for(int i =0;i<index-1;i++){// aldready it is at head
//         p = p->next;
//         q = q->next;

//     }

//     p->next = q;

//     return head;

// }

// Case 2: Deleting the element at a given index from the linked list
node * delete(node * head, int index){
    node *p = head;
    node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
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
    head = delete(head,2);
    traversal(head);
    
    return 0;
}
