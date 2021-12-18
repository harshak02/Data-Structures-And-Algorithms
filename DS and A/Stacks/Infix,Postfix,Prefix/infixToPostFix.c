#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    int size;
    int top;
    char *arr;
}stack;

int isEmpty(stack *sp){
    if(sp->top==-1){
        return 1;
    }
    return 0;
}

int isFull(stack *sp){
    if(sp->top==sp->size-1){
        return 1;
    }
    return 0;
}

void push(stack *sp,char ch){

    if(isFull(sp)){
        printf("StackOverFlown\n");
        exit(0);
    }

    else{
        sp->top++;
        sp->arr[sp->top] = ch;
    }
}

char pop(stack *sp){

    char ch;

    if(isEmpty(sp)){
        printf("StackUnderFlown\n");
    }

    else{
        ch = sp->arr[sp->top];
        sp->top--;
    }

    return ch;
}

void process(stack *sp,char str[100]){

    for(int i =0;i<strlen(str);i++){
        
    }
}

int main(){

    char str[100];
    char postFix[100];
    printf("Enter the Infix Expression\n");
    gets(str);

    stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));

    process(sp,str);

    printf("The postfix expression is %s\n",postFix);

    return 0;
}
