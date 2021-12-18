#include<iostream>
using namespace std;
//making use of arrays as primary data storage types

class stack{

    public :
    int top;
    int size;
    int *arr;

    stack(int val){
        top = -1;
        size = val;
    }
};

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

void enqueue(stack *sp,int val){

    if(isFull(sp)){
        cout<<"The stcak is overflown"<<endl;
    }

    else{
        sp->top++;
        sp->arr[sp->top] = val;   
    }

}

int pop(stack *sp){

    int val = -1;//default

    if(isEmpty(sp)){
        cout<<"The stack is Empty"<<endl;
    }

    else{
        val = sp->arr[sp->top];
        sp->top--;
    }

    return val;
}

int dequeue(stack *sp){

    stack *sp2;
    sp2 = new stack(sp->size);
    sp2->arr = new int[sp2->size];
    int val = -1;

    if(isEmpty(sp)){
        cout<<"The stack is underflown"<<endl;
    }

    else{

        while(!isEmpty(sp)){
            int temp = pop(sp);
            enqueue(sp2,temp);
        }

        val = sp2->arr[sp2->top];
        sp2->top--;

        while(!isEmpty(sp2)){
            int temp = pop(sp2);
            enqueue(sp,temp);
        }

    }
    return val;
}

int findNthindex(stack *sp,int key){

    int ind = -1;
    for(int i = 0;i<sp->size;i++){
        if(key==sp->arr[i]){
            ind = i;
            break;
        }
    }

    return ind;
}

int findIndex(stack*sp,int ind){

    int val;
    val = sp->arr[ind];
    return val;
}

void traversal(stack *sp){

    for(int i = 0;i<=sp->top;i++){
        int temp = sp->arr[i];
        cout<<temp<<" ";
    }

    cout<<endl;
}

int main(){

    int size;
    cout<<"Enter the size of the stack"<<endl;
    cin>>size;

    stack *sp;
    sp = new stack(size);
    sp->arr = new int[sp->size];

    for(int i = 0;i<size;i++){
        int temp;
        cout<<"Enter the element no. : "<<i+1<<endl;
        cin>>temp;

        enqueue(sp,temp);
    }

    traversal(sp);

    cout<<"The element is dequeued and it is "<<dequeue(sp)<<endl;
    cout<<"The element is dequeued and it is "<<dequeue(sp)<<endl;

    traversal(sp);

    int key = 50;
    cout<<"The key value "<<key<<" is present at index no. "<<findNthindex(sp,key)<<endl;

    int ind = 2;
    cout<<"The element at the index "<<ind<<" is "<<findIndex(sp,ind)<<endl;
    
    cout<<"The element is dequeued and it is "<<dequeue(sp)<<endl;
    cout<<"The element is dequeued and it is "<<dequeue(sp)<<endl;

    traversal(sp);
    
    return 0;
}
