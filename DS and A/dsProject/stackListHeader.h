#ifndef stackListHeader
#include "nodeDeclaration.h"
#include "linkedListHeader.h"
#include <iostream>
using namespace std;

node *top = NULL;

int isEmptyS(){

    if(top==NULL){
        return 1;
    }

    return 0;
}

int isFullS(){

    node * test_node;
    test_node = new node(0);

    if(test_node==NULL){
        return 1;
    }

    return 0;
}

int pop(){

    int value = -1;

    if(isEmptyS()){
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
    
    if(isFullS()){
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

#define stackListHeader
#endif