#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node *f = NULL;
struct Node *r = NULL;

typedef struct Node{
    int data;
    struct Node *next;
}node;

void traversal(node *ptr){

    while(ptr!=NULL){
        printf("%d ",ptr->data);

        ptr = ptr->next;
    }
    printf("\n");
}

int isFull(){
    node *ptr;
    ptr = (node*)malloc(sizeof(node));

    if(ptr==NULL){
        return 1;
    }

    return 0;
}

int isEmpty(){

    if(f==NULL){
        return 1;
    }

    return 0;
}

void enqueue(int val){

    if(isFull()){
        printf("The queue is overflown\n");
        exit(0);
    }

    else{

        node *n;
        n = (node*)malloc(sizeof(node));
        n->data = val;
        n->next = NULL;

        if(f==NULL){
            f=r=n;
        }

        else{
            r->next = n;
            r = n;
        }

    }
}

int dequeue(){

    int val = -1;
    if(isEmpty()){
        printf("The queue is empty\n");
    }

    else{
        node *ptr;
        ptr = f;
        f = f->next;
        val = ptr->data;
        free(ptr); 
    }

    return val;
}

int main(){
    
    printf("The dequeing element is %d\n",dequeue());
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    traversal(f);
    printf("The dequeing element is %d\n",dequeue());
    printf("The dequeing element is %d\n",dequeue());
    printf("The dequeing element is %d\n",dequeue());
    traversal(f);
    
    return 0;
}
