#include<iostream>
using namespace std;

class node{

    public :
    int data;
    node * next;

    node(int val){
        data = val;
        next = NULL;
    }
};

node *top = NULL;

int isEmpty(){

    if(top==NULL){
        return 1;
    }

    return 0;
}

int isFull(){

    node * test_node;
    test_node = new node(0);

    if(test_node==NULL){
        return 1;
    }

    return 0;
}

int pop(){

    int value = -1;

    if(isEmpty()){
        cout<<"The stack is Underflown"<<endl;
    }

    else{
        value = top->data;
        node *ptr = top;
        ptr = ptr->next;
        top = ptr;
    }

    return value;
}

void push(int val){

    node * ins_node;
    ins_node = new node (val);
    
    if(isFull()){
        cout<<"The stack is overflown"<<endl;
    }

    else{
        if(top==NULL){
            top = ins_node;
        }

        else{
            ins_node->next = top;
            top = ins_node;
        }
    }
}


int stackTop(){
    int value;
    value = top->data;

    return value;
}

int stackBottom(){

    node *ptr = top;
    int value;

    while(ptr->next!=NULL){
        ptr = ptr->next;
    }

    value = ptr->data;

    return value;

}

int peek(int ind){

    int val;
    node *ptr = top;

    for(int i = 0;i<ind-1;i++){
        ptr = ptr->next;
    }

    val = ptr->data;
    return val;
}

int sizeOfstack(){

    node *ptr = top;
    int i = 0;

    while(ptr!=NULL){
        i++;
        ptr = ptr->next;
    }

    return i; 
}

void traversal(){

    node *ptr = top;

    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    cout<<endl;
}

int indexOfValue(int key){

    int val = -1;
    node *ptr = top;
    int ind = 0;

    while(ptr!=NULL){
        if(ptr->data==key){
            break;
        }
        ind++;
        ptr = ptr->next;
    }

    val = ind;

    return val;

}

int valueAtIndex(int ind){

    int val;
    node *ptr = top;
    int i = 0;

    for(i;i<ind;i++){
        ptr = ptr->next;
    }

    val = ptr->data;

    return val;
}

int main(){

    if(isEmpty()){
        cout<<"The stack is Empty"<<endl;
    }

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    traversal();

    if(isFull()){
        cout<<"the stack is Overflown"<<endl;
    }

    else{
        cout<<"The stack is not full"<<endl;
    }

    cout<<"The element in the stcak is popped and it is "<<pop()<<endl;
    cout<<"The element in the stcak is popped and it is "<<pop()<<endl;

    int val;
    int ind = 3;
    val = peek(3);
    cout<<"The value of the 3rd position element from top is "<<val<<endl;

    cout<<"The size of the stack is "<<sizeOfstack()<<endl;

    cout<<"The bottom most Element of the stack is "<<stackBottom()<<endl;

    cout<<"The top most Element of the stack is "<<stackTop()<<endl;

    push(100);
    push(110);

    traversal();

    int temp1;
    temp1 = valueAtIndex(3);//this is from the start and gives index but not position;
    cout<<"The value of the 3rd index element is "<<temp1<<endl;

    int temp2;
    temp2 = indexOfValue(100);//this gives the index of the given value her it is 1000;
    cout<<"The index of the 100 from the start is "<<temp2<<endl;

    
    return 0;
}
