#include<stdio.h> 
#include<stdlib.h> 

struct Node{

    int data;
    struct Node *next;
    
};

void traversal(struct Node *ptr){

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    struct Node *head;
    head = (struct Node*)malloc(sizeof(struct Node));

    struct Node *second;
    second = (struct Node*)malloc(sizeof(struct Node));

    struct Node *third;
    third = (struct Node*)malloc(sizeof(struct Node));

    struct Node *fourth;
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 66;
    third->next = fourth; 

    fourth->data = 69;
    fourth->next = NULL;     

    traversal(head);

    return 0;
}
