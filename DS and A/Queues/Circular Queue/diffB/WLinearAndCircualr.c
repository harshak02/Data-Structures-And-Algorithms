#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue{
    int size;
    int f;
    int r;
    int *arr;
}queue;

void traversal(queue *q){

    for(int i =(q->f)+1;i<=q->r;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

int isEmpty(queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

int isFull(queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(queue *q,int data){

    if(isFull(q)){
        printf("Queue Overflown\n");
    }

    else{
        q->r++;
        q->arr[q->r] = data;
    }

}

int dequeue(queue *q){

    int res;
    if(isEmpty(q)){
        printf("Queue Underflown\n");
    }

    else{
        q->f++;
        res = q->arr[q->f];

    }
    return res;

}

int main(){

    queue q;
    queue *ptr = &q;
    // ptr = (queue*)malloc(sizeof(queue));not necessary
    q.size = 3;
    q.r = -1;
    q.f = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    // enque(ptr,1);
    // enque(ptr,2);
    // enque(ptr,3);
    // enque(ptr,4);
    // enque(ptr,5);
    // traversal(ptr);
    // printf("The deleted element is %d\n",deque(ptr));
    // enque(ptr,7);
    // traversal(ptr);
    // printf("The deleted element is %d\n",deque(ptr));
    // traversal(ptr);

    enqueue(ptr,10);
    enqueue(ptr,20);
    enqueue(ptr,30);
    traversal(ptr);
    printf("The dequeued element is %d\n",dequeue(ptr));
    printf("The dequeued element is %d\n",dequeue(ptr));
    traversal(ptr);
    enqueue(ptr,20);
    enqueue(ptr,30);
    printf("The dequeued element is %d\n",dequeue(ptr));
    enqueue(ptr,40);
    printf("The dequeued element is %d\n",dequeue(ptr));
    traversal(ptr);
    
    return 0;
}
