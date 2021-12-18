#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
};
 
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 4;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Empty : %d\n",isEmpty(sp));
    printf("Full : %d\n",isFull(sp));
    push(sp,231);
    push(sp,232);
    push(sp,233);
    push(sp,234);
    printf("Empty : %d\n",isEmpty(sp));
    printf("Full : %d\n",isFull(sp));
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    printf("Empty : %d\n",isEmpty(sp));
    printf("Full : %d\n",isFull(sp));
    printf("Stack has been created successfully\n");
 
    return 0;
}
