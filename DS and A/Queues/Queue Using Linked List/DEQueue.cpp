#include<iostream>
using namespace std;

class Node{

    public :
    int data;
    Node *next;
};

Node *f = NULL;
Node *r = NULL;

void traversal(Node *ptr){

    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    cout<<endl;
}

int isFull(){
    Node *ptr;
    ptr = new Node();

    if(ptr==NULL){
        return 1;
    }

    return 0;

}

int isEmpty(){

    if(f==NULL){
        return 1;
    }

    return 0;
}

void enqueFromEnd(int val){

    if(isFull()){
        cout<<"queue is overflown"<<endl;
        exit(0);
    }

    else{
        Node *n;
        n = new Node();
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }

        else{
            r->next = n;
            r = n;
        }
    }
}

int dequeFromStart(){

    int val = -1;

    if(isEmpty()){
        cout<<"Queue is Underflown"<<endl;
    }

    else{
        Node *ptr;
        ptr = f;
        f = f->next;
        val = ptr->data;
        delete ptr;
    }

    return val;
}

void enqueFromStart(int val){

    if(isFull()){
        cout<<"Queue is Overflown"<<endl;
        exit(0);
    }

    else{
        Node *n;
        n = new Node();
        n->data = val;

        if(f==NULL){
            n->next = NULL;
            f=r=n;
        }

        else{
            n->next = f;
            f = n;
        }
    }
}

int dequeFromEnd(){
    int val = -1;
    
    if(isEmpty()){
        cout<<"Queue is Underflown"<<endl;
    }

    else{
        Node *ptr;
        ptr = r;
        Node *ptr2;
        ptr2 = f;

        while((ptr2->next)->next!=NULL){
            ptr2 = ptr2->next;
        }

        ptr2->next = NULL;
        val = ptr->data;
        r = ptr2;
        delete ptr;

    }

    return val;
}

int main(){

    cout<<"The Dequeueing element is ";
    cout<<dequeFromStart()<<endl;
    enqueFromEnd(10);
    enqueFromEnd(20);
    enqueFromEnd(30);
    enqueFromEnd(40);
    traversal(f);
    enqueFromStart(50);
    enqueFromStart(60);
    traversal(f);
    cout<<"The Dequeueing element is ";
    cout<<dequeFromStart()<<endl;
    cout<<"The Dequeueing element is ";
    cout<<dequeFromStart()<<endl;
    cout<<"The Dequeueing element is ";
    cout<<dequeFromStart()<<endl;
    cout<<"The Dequeueing element is ";
    cout<<dequeFromStart()<<endl;
    cout<<"The Dequeueing element is ";
    cout<<dequeFromStart()<<endl;
    cout<<"The Dequeueing element is ";
    cout<<dequeFromStart()<<endl;
    enqueFromStart(100);
    enqueFromStart(200);
    enqueFromStart(300);
    enqueFromStart(400);
    enqueFromStart(500);
    traversal(f);
    cout<<"The Dequeueing element is ";
    cout<<dequeFromEnd()<<endl;
    cout<<"The Dequeueing element is ";
    cout<<dequeFromEnd()<<endl;
    cout<<"The Dequeueing element is ";
    cout<<dequeFromEnd()<<endl;
    traversal(f);


    return 0;
}
