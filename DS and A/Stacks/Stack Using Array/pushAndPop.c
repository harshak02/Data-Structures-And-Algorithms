#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{

    int size;
    int top;
    int *arr;
}stack;

int isFull(stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int main(){

    int val = 4;//user input;
    stack *sp;
    sp = (stack*)malloc(sizeof(stack));
    sp->size = 8;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size*sizeof(int));

    //push// think like there are no elements first
    if(isFull(sp)){
        printf("Stack OverFlow\n");
    }

    else{
        sp->top++;
        sp->arr[sp->top] = val;
    }
    
    //pop/think like there are full elements first
    int result = -1;

    if(isEmpty(sp)){
        printf("Stack underflow\n");
    
    }

    else{
        result = sp->arr[sp->top];
        sp->top--; 
    }

    return 0;
}
