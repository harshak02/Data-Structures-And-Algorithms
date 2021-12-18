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

node * insertion(node *head,node *ins,int elem){

    node* ptr;
    ptr = (node*)malloc(sizeof(node));

    ptr->data = elem;

    node *p;
    p = head;
    int i =0;

    while(1){
        if(p->data == ins->data){
            i++;
            break;
        }
        p = p->next;
    }

    node *pi;
    pi = head;

    for(int j = 0;j<i-1;j++){
        pi = pi->next;
    }

    ptr->next  = pi->next;
    pi->next = ptr;

    return head;

}


int main(){

    node *ins;
    ins = (node*)malloc(sizeof(node));

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
    head = insertion(head,second,90);
    traversal(head);
    
    return 0;
}
