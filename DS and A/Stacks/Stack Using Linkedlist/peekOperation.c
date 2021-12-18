#include<stdio.h> 
#include<stdlib.h>

typedef struct Node{

    int data;
    struct Node *next;
}node;

void traversal(node * ptr){

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

}

int stackTop(node * top){
    return top->data;
}

int stackBottom(node *ptr){
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    int res = ptr->data;
    return res;
}

int isFull(){
    node * ptr;
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

node * push(node * top,int num){

    if(isFull()){
        printf("StackOverflown\n");
    }

    else{
        node * ptr;
        ptr = (node*)malloc(sizeof(node));
        ptr->data = num;
        ptr->next = top;
        top = ptr;
    }
}

int pop(node ** top){

    int res;
    if(isEmpty(*top)){
        printf("StackUnderflown\n");
        return -1;
    }

    else{
        res = (*top)->data;
        *top = (*top)->next;
        return res;
    }
}

int peek(node * top,int index){
    int res;
    if(isEmpty(top)){
        printf("StackUnderflown\n");
        return -1;
    }

    else{
        node *ptr;
        ptr = top;
        for(int i = 1;i<index;i++){
            ptr = ptr->next;
        }
        res = ptr->data;
        return res;
    }
}

int main(){
    node *top = NULL;
    int x,y,z;
    top = push(top,10);
    top = push(top,20);
    top = push(top,30);
    top = push(top,40);
    top = push(top,50);
    top = push(top,60);
    traversal(top);
    printf("\n");
    x = pop(&top);
    printf("The popped element in the stack is %d\n",x);
    y = pop(&top);
    printf("The popped element in the stack is %d\n",y);
    traversal(top);
    printf("\n");
    z = peek(top,3);
    printf("The 3rd element in the stack is %d\n",z);
    printf("The topmost data of the stack is %d\n",stackTop(top));
    printf("The bottomost data of the stack is %d\n",stackBottom(top));
    
    return 0;
}
