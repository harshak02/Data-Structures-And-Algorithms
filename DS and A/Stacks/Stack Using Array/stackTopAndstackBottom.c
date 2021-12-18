#include<stdio.h> 
#include<stdlib.h>

// top+1 is the simple logic 

typedef struct Stack{
    int size ;
    int top;
    int * arr;
}stack;
 
int isEmpty(stack * ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(stack * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int peek(stack *sp,int key){
    int res;
    res = sp->arr[sp->top-key+1];
    return res;

}

void push(stack * sp, int val){
    if(isFull(sp)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        sp->top++;
        sp->arr[sp->top] = val;
    }
}

int stackTop(stack *sp){
    return sp->arr[sp->top];
}

int stackBottom(stack *sp){
    return sp->arr[0];
}

int main(){

    int res;
    stack *sp;
    sp = (stack*)malloc(sizeof(stack));
    sp->size = 8;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size*sizeof(int));

    push(sp,23);
    push(sp,24);
    push(sp,25);
    push(sp,26);

    for(int i = 0;i<sp->top+1;i++){
        int temp;
        temp = peek(sp,i+1);
        printf("The %d element from top is %d\n",i+1,temp);
    }

    printf("The top most value of stcak is %d\n",stackTop(sp));
    printf("The Bottom most value of stcak is %d\n",stackBottom(sp));
    
    return 0;
}
