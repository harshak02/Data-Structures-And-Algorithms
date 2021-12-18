#include<iostream>
using namespace std;

class queue{

    public :
    int size;
    int f;
    int r;
    int *arr;

    queue(int val){
        size = val;
        f = -1;
        r = -1;
    }
};

int isEmpty(queue *q){

    if(q->r == -1 && q->f == -1){
        return 1;
    }

    return 0;
}

int isFull(queue *q){

    if(q->r == q->size-1){
        return 1;
    }

    return 0;
}

void enqueueFromStart(queue *q,int val){

    if(isFull(q)){
        cout<<"The queue is Overflown"<<endl;
    }

    else{
        q->arr[q->f] = val;
        q->f--;
    }
}

void enqueueFromEnd(queue *q,int val){

    if(isFull(q)){
        cout<<"The queue is Overflown"<<endl;
    }

    else{
        q->r++;
        q->arr[q->r] = val;
    }

}

int dequeueFromEnd(queue *q){

    int val = -1;

    if(isEmpty(q)){
        cout<<"The queue is Underflown"<<endl;
    }

    else{
        val = q->arr[q->r];
        q->r--;
    }

    return val;
}

int dequeueFromStart(queue *q){

    int val = -1;

    if(isEmpty(q)){
        cout<<"The queue is Underflown"<<endl;
    }

    else{
        q->f++;
        val = q->arr[q->f];
    }

    return val;
}

void traversal(queue *q){

    for(int i = q->f+1;i<=q->r;i++){
        int temp;
        temp = q->arr[i];
        cout<<temp<<" ";
    }
    cout<<endl;
}

int main(){

    int size;
    cout<<"Enter the size of the queue"<<endl;
    cin>>size;

    queue *q;
    q = new queue(size);
    q->arr = new int[q->size];

    for(int i = 0;i<size-2;i++){
        int temp;
        cout<<"Enter the element no. : "<<i+1<<endl;
        cin>>temp;
        enqueueFromEnd(q,temp);
    }

    traversal(q);

    enqueueFromStart(q,100);
    enqueueFromStart(q,200);

    traversal(q);

    cout<<"The element is dequeued from start and it is "<<dequeueFromStart(q)<<endl;
    cout<<"The element is dequeued from start and it is "<<dequeueFromStart(q)<<endl;

    cout<<"The element is dequeued and from end it is "<<dequeueFromEnd(q)<<endl;
    cout<<"The element is dequeued and from end it is "<<dequeueFromEnd(q)<<endl;

    traversal(q);
    
    return 0;
}
