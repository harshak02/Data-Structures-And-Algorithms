#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

typedef struct Stack{
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

void push(stack *sp,char c){
    if(isFull(sp)){
        printf("Stack Overflow\n");
    }

    else{
        sp->top++;
        sp->arr[sp->top] = c; 
    }
}

char pop(stack *sp){

    char c;
    if(isEmpty(sp)){
        printf("Stack UnderFlown\n");
        printf("The mathermatical reasoning is illogical\n");
        exit(0);
    }

    else{
        sp->top--;
        c = sp->arr[sp->top];
    }
    return c;
}

void process(stack *sp,char str[100]){
    char c;

    for(int i =0;i<strlen(str);i++){
        if(str[i]=='('){
            push(sp,str[i]);
        }

        else if(str[i]==')'){
            c = pop(sp);
        }
    }
}


int main(){

    char str[100];
    printf("Enter the mathametical Expression\n");
    gets(str);

    stack *sp;
    sp->size = strlen(str);
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));

    process(sp,str);

    if(isEmpty(sp)){
        printf("The given Expression is logical\n");
    }

    else{
        printf("The given expression is illogical\n");
    }

    return 0;
}
