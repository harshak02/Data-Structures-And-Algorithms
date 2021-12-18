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
        printf("Sorry! StackOverflown\n");
        exit(0);
    }

    else{
        sp->top++;
        sp->arr[sp->top] = c;
    }
}

char pop(stack *sp){
    char temp;
    if(isEmpty(sp)){
        printf("Sorry! StackUnderflown\n");
        printf("The given expression is illogical\n");
        exit(0);
    }

    else{
        temp = sp->arr[sp->top];
        sp->top--;
    }
    return temp;
}

int match (char a,char b){
    if(a==b){
        return 1;
    }

    else{
        printf("The expression is illogical\n");
        exit(0);
    }
}

int stackTop(stack *sp){
    return sp->arr[sp->top];
}

void process(stack *sp,char str[100]){

    char temp;
    for(int i = 0;i<strlen(str);i++){
        switch(str[i]){
            case '(' :
            push(sp,'(');
            break;

            case ')' :
            if(match('(',stackTop(sp))){
                temp = pop(sp);
            }
            break;

            case '{' :
            push(sp,'{');
            break;

            case '}' :
            if(match('{',stackTop(sp))){
                temp = pop(sp);
            }
            break;

            case '[' :
            push(sp,'[');
            break;

            case ']' :
            if(match('[',stackTop(sp))){
                temp = pop(sp);
            }
            break;
        }
    }
}

int main(){

    char str[100];
    printf("Enter the mathematical Expression\n");
    gets(str);

    stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));

    process(sp,str);

    if(isEmpty(sp)){
        printf("The given expression is logical\n");
    }

    else{
        printf("The given expression is illogical\n");
    }
    
    return 0;
}
