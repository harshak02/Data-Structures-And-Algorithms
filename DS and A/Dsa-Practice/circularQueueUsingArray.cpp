#include<iostream>
using namespace std;

class queue{
    
    public :

    int size;
    int f;
    int r;
    int *arr;

    queue(){
        f = 0;
        r = 0;
    }
};

void traversal(queue *ptr){

    if(ptr->f<=ptr->r){

        int i = ptr->f;
        for(i;i<ptr->r;i++){
            cout<<ptr->arr[i]<<" ";
        }
        cout<<endl;
    }

    else{
        int i = ptr->f;
        for(i;i<ptr->size;i++){
            cout<<ptr->arr[i]<<" ";

        }

        for(int i = 0;i<ptr->r;i++){
            cout<<ptr->arr[i]<<" ";
        }
        cout<<endl;
    }

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

    if((ptr->r+1)%ptr->size == ptr->f){
        return 1;
    }

    else{
        return 0;
    }
}
//front wont point to an element but rear will point
void enqueue(queue *ptr,int val){

    if(isFull(ptr)){
        cout<<"The queue is Overflown"<<endl;
    }

    else{
        ptr->arr[ptr->r] = val;
        ptr->r = (ptr->r+1)%ptr->size;
    }

}

int dequeue(queue *ptr){

    int val = -1;

    if(isEmpty(ptr)){
        cout<<"The Queue is Underflown"<<endl;
    }

    else{
        val = ptr->arr[ptr->f];
        ptr->f = (ptr->f+1)%ptr->size;
    }

    return val;

}

int main(){

    queue q;
    queue *ptr = &q;

    int size;
    cout<<"Enter the size of the queue :-"<<endl;
    cin>>size;

    q.size = size+1;
    q.arr = new int[q.size];

    int l;
    l = isEmpty(ptr);
    if(l==1){
        cout<<"The queue is Underflown"<<endl;
    }

    cout<<endl;

    for(int i = 0;i<q.size-1;i++){//important in circular queue we take size-1
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

    int m;
    m = isEmpty(ptr);

    if(m==1){
        cout<<"The queue is Underflown"<<endl;
    }

    enqueue(ptr,100);
    enqueue(ptr,200);
    traversal(ptr);


    return 0;
}
