#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node{

    int data;
    struct Node *next;
    
}type;

int main(){

    type *head;
    head = (type*)malloc(sizeof(type));

    type *second;
    second = (type*)malloc(sizeof(type));

    type *third;
    third = (type*)malloc(sizeof(type));

    head->data = 7;
    head->next = second;

    head->data = 11;
    head->next = third;

    head->data = 66;
    head->next = NULL;   

    return 0;
}
