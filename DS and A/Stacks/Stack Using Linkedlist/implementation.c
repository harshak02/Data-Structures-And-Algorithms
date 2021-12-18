#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node{
    int data;
    struct Node *next;
}node;

int isFull(){
    node *ptr;
    ptr = (node*)malloc(sizeof(node));

    if(ptr==NULL){
        return 1;
    }

    return 0;
}

int isEmpty(node * top){

    if(top==NULL){
        return 1;
    }

    return 0;
}

void traversal(node * ptr){

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

node * push(node *top,int num){

    if(isFull()){
        printf("Stack Overflown\n");
    }

    else{
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->data = num;
    ptr->next = top;
    top = ptr;
    }

    return top;
}

int pop(node **top){

    int num;
    if(isEmpty(*top)){
        printf("Stack Underflown\n");
    }

    else{
        num = (*top)->data;
        *top = (*top)->next;
        // free(ptr);
    }

    return num;
}

int main(){
    
    node *top;
    top = NULL;
    int res;

    top = push(top,78);
    top = push(top,79);
    top = push(top,80);
    top = push(top,81);
    top = push(top,82);
    traversal(top);
    res = pop(&top);
    printf("The popped element is %d\n",res);
    traversal(top);

    return 0;
}

