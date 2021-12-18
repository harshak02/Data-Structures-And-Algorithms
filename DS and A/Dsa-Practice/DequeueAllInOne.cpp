#include<iostream>
using namespace std;

class node{

    public :

    int data;
    node * next;

    node(int val){
        data = val;
    }

    node(){

    }
};

node *f = NULL;
node *r = NULL;

void traversal(){

    node *ptr = f;

    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    cout<<endl;
}

int isEmpty(){

    if(f==NULL && r==NULL){
        return 1;
    }

    else{
        return 0;
    }
}

int isFull(){

    node *test_node;
    test_node = new node(0);

    if(test_node==NULL){
        return 1;
    }

    else{
        return 0;
    }

}

int dequeueFromStart(){

    int val = -1;

    if(isEmpty()){
        cout<<"The Queue is Underflown"<<endl;
    }

    else{

        node * ptr = f;

        if(ptr==r){
            r = NULL;
        }

        val = ptr->data;
        ptr = ptr->next;
        f = ptr;
    }

    return val;
}

int dequeueFromEnd(){

    int val = -1;
    if(isEmpty()){
        cout<<"The Queue is Underflown"<<endl;
    }

    else{
        node *ptr1 = r;
        node *ptr2 = f;

        if(f==ptr1){
            f == NULL;
        }

        while((ptr2->next)->next!=NULL){
            ptr2 = ptr2->next;
        }
        val = ptr1->data;
        r = ptr2;
        delete ptr1;

    }

    return val;
}

void enqueueFromStart(int val){

    if(isFull()){
        cout<<"The queue is Overflown"<<endl;
    }

    else{

        node * ins_node;
        ins_node = new node(val);
        
        node *ptr = f;

        if(ptr==NULL){
            f = r = ins_node;
        }

        else{
            ins_node->next = f;
            f = ins_node;
        }

    }
}

void enqueueFromEnd(int val){

    if(isFull()){
        cout<<"The Queue is Overflown"<<endl;
    }

    else{
        node *ins_node;
        ins_node = new node(val);
        ins_node->next = NULL;

        if(f==NULL){
            f = ins_node;
            r = ins_node;
        }

        else{
            r->next = ins_node;
            r = ins_node;
        }
    }
}


int main(){

    int size;
    cout<<"Enter the size of the De Queue"<<endl;
    cin>>size;

    if(isEmpty()){
        cout<<"The Queue is Empty"<<endl;
    }

    for(int i = 0;i<size;i++){

        int temp;
        cout<<"Enter the element number "<<i+1<<endl;
        cin>>temp;
        enqueueFromEnd(temp);
    }

    if(isFull()){
        cout<<"The Queue is Full"<<endl;
    }

    traversal();

    enqueueFromStart(100);
    enqueueFromStart(200);
    enqueueFromStart(300);
    enqueueFromStart(400);
    enqueueFromStart(500);

    traversal();

    cout<<"The element Dequeued from the start is "<<dequeueFromStart()<<endl;
    cout<<"The element Dequeued from the start is "<<dequeueFromStart()<<endl;
    traversal();
    cout<<"The element Dequeued from the End is "<<dequeueFromEnd()<<endl;
    cout<<"The element Dequeued from the End is "<<dequeueFromEnd()<<endl;
    traversal();

    
    return 0;
}
