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

    // stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int*)malloc(s.size*sizeof(int));

    // but it is necessary to write in pointer;

    stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    // adding elements;
    s->arr[0] = 4;
    s->top++;

    if(isEmpty(s)){
        printf("The stack is empty\n");
    }

    else{
        printf("the stack is not empty\n");
    }

    
    return 0;
}
