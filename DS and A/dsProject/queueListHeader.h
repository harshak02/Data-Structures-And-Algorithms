#ifndef queueListHeader
#include "nodeDeclaration.h"
#include  "linkedListHeader.h"
#include <iostream>
using namespace std;


node *f = NULL;
node *r = NULL;

int isFullQ(){

    node * test_node;
    test_node = new node(0);

    if(test_node==NULL){
        return 1;
    }

    else{
        return 0;
    }
}

int isEmptyQ(){

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

void enqueue(int val){

    if(isFullQ()){
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

int dequeue(){

    int val = -1;

    if(isEmptyQ()){
        cout<<"The queue is Underflown"<<endl;
    }

    else{

        node * ptr = f;
        val = ptr->data;
        ptr = ptr->next;
        f = ptr;
        
    }

    return val;

}

#define queueListHeader
#endif