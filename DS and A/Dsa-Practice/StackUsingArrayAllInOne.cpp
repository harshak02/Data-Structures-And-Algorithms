#include<iostream>
using namespace std;

class stack{

    public :
    int top;
    int size;
    int *arr;

    stack(){
        top = -1;
    }
};

void traversal(stack *sp){

    int i = 0;
    while(i<=sp->top){
        cout<<sp->arr[i]<<" ";
        i++;
    }

    cout<<endl;
}

int sizeOfStack(stack *sp){
    int size;
    size = sp->size;

    return size;
}

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

void push(stack *sp,int val){

    if(isFull(sp)){
        cout<<"The stcak is Full"<<endl;
    }

    else{
        sp->arr[sp->top+1] = val;
        sp->top++;
    }
    
}

int peek(stack *sp,int index){
    //Considering from the top and considering postions not indices
    int val = -1;
    val = sp->arr[sp->top-index+1];
    return val;
}

int stackBottom(stack *sp){

    int val = sp->arr[0];
    return val;
}

int stackTop(stack *sp){

    int val = sp->arr[sp->top];
    return val;
}

int valueAtIndex(stack *sp,int ind){
    int val;
    val = sp->arr[ind];
    //this is from bottom count
    return val;
}

int indexOfValue(stack *sp,int key){

    int i = 0;
    for(i;i<sp->size;i++){
        if(key==sp->arr[i]){
            break;
        }
    }

    int ind = i;
    return ind;
}

int main(){

    stack *sp;
    sp = new stack();

    int sizeImp;
    cout<<"Enter the size of the stack"<<endl;
    cin>>sizeImp;

    sp->size = sizeImp;
    sp->arr = new int[sizeImp];

    cout<<endl;

    if(isEmpty(sp)){
        cout<<"The stack is Empty"<<endl;
    }
    cout<<endl;

    for(int i = 0;i<sp->size;i++){
        int temp;
        cout<<"Enter the element no : "<<i+1<<endl;
        cin>>temp;
        push(sp,temp);
    }
    cout<<endl;

    traversal(sp);
    cout<<endl;

    if(isFull(sp)){
        cout<<"The stack is Full"<<endl;
    }

    int size;
    size = sizeOfStack(sp);
    cout<<"The size of the stack is "<<size<<endl;

    int stktop;
    stktop = stackTop(sp);
    cout<<"The value of the topmost element of the stak is "<<stktop<<endl;

    int stkbtm;
    stkbtm = stackBottom(sp);
    cout<<"The value of the bottom most element of the stak is "<<stkbtm<<endl;
    
    int temp0;
    int position;
    cout<<"Enter the psosition to find the value at that index"<<endl;
    cin>>position;
    temp0 = peek(sp,position);
    cout<<"The value of the "<<position<<" position from the top is "<<temp0<<endl;
    cout<<endl;

    int temp1;
    temp1 = pop(sp);
    cout<<"The element popped out is "<<temp1<<endl;
    cout<<"The stack now is"<<endl;
    traversal(sp);
    cout<<endl;

    int temp2;
    temp2 = pop(sp);
    cout<<"The element popped out is "<<temp2<<endl;\
    cout<<"The stack now is"<<endl;
    traversal(sp);
    cout<<endl;

    int temp3;
    temp3 = valueAtIndex(sp,3);
    cout<<"The value at the index "<<3<<" is "<<temp3<<endl;

    int temp4;
    temp4 = indexOfValue(sp,20);
    cout<<"The index of the data "<<20<<" from the start is "<<temp4<<endl;
    
    return 0;
}
