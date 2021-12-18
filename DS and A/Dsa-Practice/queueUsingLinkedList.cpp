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

int isFull(){

    node * test_node;
    test_node = new node(0);

    if(test_node==NULL){
        return 1;
    }

    else{
        return 0;
    }
}

int isEmpty(){

    if(f==NULL){
        return 1;
    }

    else{
        return 0;
    }
}

// void traversal(){

//     node *ptr = f;

//     while(ptr!=NULL){
//         cout<<ptr->data<<" ";
//         ptr = ptr->next;
//     }

//     cout<<endl;
// }

void traversal(){

    node *ptr = f;

    while(ptr!=NULL){
        printf("%d ",ptr->data);

        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int val){

    if(isFull()){
        cout<<"The queue is Overflown"<<endl;
    }

    else{
        node *ins_node;
        ins_node = new node(val);

        ins_node->data = val;
        ins_node->next = NULL;

        if(f==NULL){
            f = r = ins_node;
        }

        else{
            r->next = ins_node;
            r = ins_node;
        }

    }
}

// int dequeue(){

//     int val = -1;

//     if(isEmpty()){
//         cout<<"The queue is Underflown"<<endl;
//     }

//     else{

//         node * ptr = f;
//         val = ptr->data;
//         ptr = ptr->next;
//         f = ptr;
        
//     }

//     return val;

// }

int dequeue(){

    int val = -1;
    if(isEmpty()){
        printf("The queue is empty\n");
    }

    else{
        node *ptr;
        ptr = f;
        f = f->next;
        val = ptr->data;
    }

    return val;
}


int main(){

    int size;
    cout<<"Enter the size of the queue"<<endl;
    cin>>size;

    for(int i = 0;i<size;i++){

        int temp;
        cout<<"Enter the element no. : "<<i+1<<endl;
        cin>>temp;
        enqueue(temp);

    }

    traversal();

    cout<<"The dequeued element is "<<dequeue()<<endl;
    cout<<"The dequeued element is "<<dequeue()<<endl;
    cout<<"The dequeued element is "<<dequeue()<<endl;

    traversal();
    
    return 0;
}
