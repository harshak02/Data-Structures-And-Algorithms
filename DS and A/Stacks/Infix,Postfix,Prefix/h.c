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
    if(sp->top == sp->size-1){
        return 1;
    }
    return 0;
}

void push(stack *sp,char data){

    if(isFull(sp)){
        printf("StackOverFlown\n");
        exit(0);
    }

    else{
        sp->top++;
        sp->arr[sp->top] = data;
    }
    
}

char pop(stack *sp){

    char ch;
    if(isEmpty(sp)){
        printf("StackUnderFlown\n");
        exit(0);
    }

    else{
        ch = sp->arr[sp->top];
        sp->top--;
    }

    return ch;
    
}

char stackTop(stack *sp){
    return sp->arr[sp->top];
}

int isOperator(char c){
    if(c =='+'||c =='-'||c =='*'||c =='/'){
        return 1;
    }
    return 0;
}

int precedence(char c){
    if(c =='*'||c == '/'){
        return 3;
    }

    else if(c =='+'||c == '-'){
        return 2;
    }

    else{
        return 0;
    }
}

char *infToPos (char inf[]){

    stack *sp;
    sp = (stack *) malloc(sizeof(stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    char *pos;
    pos = (char*)malloc((strlen(inf)+1)*sizeof(char));
    int i = 0;
    int j = 0;

    while(inf[i]!='\0'){

        if(!isOperator(inf[i])){
            pos[j] = inf[i];
            j++;
            i++;
        }

        else{
            if(precedence(inf[i])>precedence(stackTop(sp))){
                push(sp,inf[i]);
                i++;
            }

            else{
                pos[j] = pop(sp);
                j++;
            }
        }
    }

    while(!isEmpty(sp)){
        pos[j] = pop(sp);
        j++;
    }

    pos[j] = '\0';

    return pos;

}


int main(){

    char inf[] = "x-y/z-k*d";
    printf("The string is %s\n",infToPos(inf));
    
    return 0;
}
