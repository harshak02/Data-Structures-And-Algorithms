#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct circularQueue{

    int size;
    int r;
    int f;
    int *arr;
}queue;

void traversal(queue *q){

    if(q->r>=q->f){
        for(int i = q->f;i<q->r;i++){
            printf("%d ",q->arr[i]);
        }
    }

    else{
        for(int i = q->f;i<q->size;i++){
            printf("%d ",q->arr[i]);
        }

        for(int i = 0;i<q->r;i++){
            printf("%d ",q->arr[i]);
        }
    }

    printf("\n");
}

int isEmpty(queue *q){

    if(q->r == q->f){
        return 1;
    }
    return 0;
}

int isFull(queue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

void enqueue(queue *q,int data){

    if(isFull(q)){
        printf("Queue Overflown\n");
        exit(0);
    }

    else{
        q->arr[q->r] = data;
        q->r = (q->r+1)%q->size;
        printf("Enqueued element is %d\n",data);
    }
}

int dequeue(queue *q){
    int res = -1;
    if(isEmpty(q)){
        printf("Queue is Underflown\n");
        exit(0);
    }

    else{
        res = q->arr[q->f];
        q->f = (q->f+1)%q->size;
    }
    return res;
}

// here even though we are taking q->f and q->r as 0 we need to do all the logics same as that of the liner 
//queue becoz the 1 element is seperately given to the q->f(counter)
int main(){

    queue qu;
    queue *q = &qu;

    qu.size = 5;
    qu.f = 0;
    qu.r = 0;
    qu.arr = (int*)malloc(qu.size*sizeof(int));

    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    traversal(q);
    printf("The dequeued element is %d\n",dequeue(q));
    printf("The dequeued element is %d\n",dequeue(q));
    traversal(q);
    enqueue(q,20);
    enqueue(q,30);
    traversal(q);    
    
    return 0;
}
