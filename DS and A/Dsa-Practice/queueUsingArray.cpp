#include<iostream>
using namespace std;

class queue{
    
    public :

    int size;
    int f;
    int r;
    int *arr;

    queue(){
        f = -1;
        r = -1;
    }
};

void traversal(queue *ptr){

    int i = (ptr->f)+1;
    for(i;i<=ptr->r;i++){
        cout<<ptr->arr[i]<<" ";
    }

    cout<<endl;
}

int isEmpty(queue *ptr){

    if(ptr->f==ptr->r){
        return 1;
    }

    else{
        return 0;
    }
}

int isFull(queue *ptr){

    if(ptr->r==ptr->size-1){
        return 1;
    }

    else{
        return 0;
    }
}

void enqueue(queue *ptr,int val){

    if(isFull(ptr)){
        cout<<"The queue is Overflown"<<endl;
    }

    else{
        ptr->r++;
        ptr->arr[ptr->r] = val;
    }
}

int dequeue(queue *ptr){

    int val = -1;

    if(isEmpty(ptr)){
        cout<<"The Queue is Underflown"<<endl;
    }

    else{
        ptr->f++;
        val = ptr->arr[ptr->f];
    }

    return val;
}


int main(){

    queue q;
    queue *ptr = &q;

    int size;
    cout<<"Enter the size of the queue :-"<<endl;
    cin>>size;

    q.size = size;
    q.arr = new int[q.size];

    int l;
    l = isEmpty(ptr);
    if(l==1){
        cout<<"The queue is Underflown"<<endl;
    }

    for(int i = 0;i<q.size;i++){
        int temp;
        cout<<"Enter the element no. "<<i+1<<endl;
        cin>>temp;
        enqueue(ptr,temp);
    }

    traversal(ptr);

    int k;
    k = isFull(ptr);
    if(k==1){
        cout<<"The queue is Overflown"<<endl;
    }

    cout<<"The element is dequeued and it is "<<dequeue(ptr)<<endl;
    traversal(ptr);
    cout<<"The element is dequeued and it is "<<dequeue(ptr)<<endl;
    traversal(ptr);
    cout<<"The element is dequeued and it is "<<dequeue(ptr)<<endl;
    traversal(ptr);
    cout<<"The element is dequeued and it is "<<dequeue(ptr)<<endl;
    traversal(ptr);
    cout<<"The element is dequeued and it is "<<dequeue(ptr)<<endl;
    traversal(ptr);
    cout<<"The element is dequeued and it is "<<dequeue(ptr)<<endl;
    traversal(ptr);

    enqueue(ptr,100);//this is demerit

    return 0;
}
