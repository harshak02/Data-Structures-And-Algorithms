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

node *f = NULL;
node *r = NULL;

int isEmpty(){

    if(f==NULL){
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

void enqueue(int value)
{
    node* temp;
    temp = new node(value);

    if (f == NULL)
        f = temp;
    else
        r->next = temp;
  
    r = temp;
    r->next = f;
}

int dequeue(){

    int val = -1;

    if(isEmpty()){
        cout<<"The queue is Underflown"<<endl;
    }

    else{

        if(f==r){
            node *ptr = f;
            val = ptr->data;
            f = NULL;
            r = NULL;
        }

        else{

            node *ptr2 = f;
            while(ptr2->next!=f){
                ptr2 = ptr2->next;
            }
            node *ptr = f;
            val = ptr->data;
            f = f->next;
        
            ptr2->next = f;
        }

    }

    return val;
}

void traversal(){

    node *ptr = f;
    while(ptr->next!=f){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    cout<<ptr->data<<" ";
    cout<<endl;
}

int main(){
    
    int size;
    cout<<"Enter the size of the circular queue"<<endl;
    cin>>size;

    if(isEmpty()){
        cout<<"The queue is empty"<<endl;
    }

    for(int i = 0;i<size;i++){
        int temp;
        cout<<"Enter the element no. : "<<i+1<<endl;
        cin>>temp;
        enqueue(temp);
    }

    traversal();

    cout<<"The element is dequeued and it is "<<dequeue()<<endl;
    cout<<"The element is dequeued and it is "<<dequeue()<<endl;
    cout<<"The element is dequeued and it is "<<dequeue()<<endl;

    traversal();

    for(int i = 0;i<size-3;i++){
        int temp;
        cout<<"Enter the element no. : "<<i+1<<endl;
        cin>>temp;
        enqueue(temp);
    }

    traversal();

    if(isFull()){
        cout<<"The queue is full"<<endl;//this may not print coz we dont have queue full 
    }

    return 0;
}
