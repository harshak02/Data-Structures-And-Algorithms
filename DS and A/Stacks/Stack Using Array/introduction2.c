#include<stdio.h> 
#include<stdlib.h>

typedef struct Stack{

    int size;
    int top;
    int *arr;
}stack;

int isEmpty(stack *ptr){
    if(ptr->top == -1){
        return 1;
    }

    return 0;
}

int isFull(stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }

    return 0;
}

int main(){

    stack *s;
    s = (stack *)malloc(sizeof(stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    // s->arr[0] = 4;
    // s->top++;
    // s->arr[1] = 1;
    // s->top++;
    // s->arr[2] = 2;
    // s->top++;
    // s->arr[3] = 3;
    // s->top++;
    // s->arr[4] = 5;
    // s->top++;
    // s->arr[5] = 0;
    // s->top++;

    int i = 0;
    for(i;i<6;i++){
        s->arr[i] = i;
        s->top++;
    }

    if(isFull(s)){
        printf("The stack is full\n");
    }

    else{
        printf("the stack is not full\n");
    }

    if(isEmpty(s)){
        printf("The stack is empty\n");
    }

    else{
        printf("the stack is not empty\n");
    }

    
    return 0;
}
