#ifndef linkedListHeader
#include "nodeDeclaration.h"
#include <iostream>
using namespace std;

node *head = NULL;

int isFull(node *head){

    node * chk_node;
    chk_node = new node(0);

    if(chk_node==NULL){
        return 1;
    }

    else{
        return 0;
    }

}

int isEmpty(node *head){

    node *ptr = head;

    if(ptr==NULL){
        return 1;
    }

    else{
        return 0;
    }
}

int findNthIndexElement(node * head,int index){

    node *ptr = head;

    for(int i = 0;i<index;i++){
        ptr = ptr->next;
    }
    int val;
    val = ptr->data;

    return val;
}

int sizeOfLinkedList(node * head){

    int res = 0;
    node *ptr = head;

    while(ptr!=NULL){
        res++;
        ptr = ptr->next;
    }
    

    return res;
}

void traversal(node * ptr){

    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }

    cout<<"NULL"<<endl;
}

node * reverse(node *head){

    node *prev = NULL;
    node *curr = head;
    node *afte;

    while(curr!=NULL){

        afte = curr->next;
        curr->next = prev;

        curr = afte;

    }

    return prev;

}

node * insertAtEnd(node * head,int val){

    node *ptr = head;
    node * ins_node;
    ins_node = new node(val);


    if(head==NULL){

        head = ins_node;  
    }

    else{

        while(ptr->next!=NULL){
            ptr = ptr->next;
        }

        ptr->next = ins_node;
    }

    return head;
}

node * insertAtStart(node *head,int val){

    node *ptr = head;
    node * ins_node;
    ins_node = new node(val);


    if(head==NULL){

        head = ins_node;  
    }

    else{
        ins_node->next = head;
        head = ins_node;
    }

    return head;

}

node * insertAtIndex(node * head,int val,int index){

    node *ptr1 = head;
    node *ptr2 = head;
    node * ins_node;
    ins_node = new node(val);

    for(int i = 0;i<index-1;i++){
       ptr1 = ptr1->next; 
       ptr2 = ptr2->next; 
    }

    ptr2 = ptr2->next;
    
    ptr1->next = ins_node;
    ins_node->next = ptr2;

    return head;

}

int findPos(node * head,int key){

    int res = -1;
    int i = 1;
    node *ptr = head;

    while(ptr!=NULL){

        if(ptr->data==key){
            res = i;
            break;
        }
        i++;
        ptr = ptr->next;
    }

    return res;
}

node * deleteAtStart(node * head){

    node *ptr = head;
    int val;
    val = ptr->data;
    ptr = ptr->next;
    head = ptr;

    cout<<"The deleted value is "<<val<<endl;

    return head;
}

node *  deleteAtEnd(node * head){

    node *ptr1 = head;
    node *ptr2 = head;
    int val;

    while((ptr1->next)->next!=NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr2 = ptr2->next;
    val = ptr2->data;
    ptr1->next = NULL;

    cout<<"The deleted value is "<<val<<endl;

    return head;
}


node * deleteAtIndex(node * head,int index){

    node *ptr1 = head;
    node *ptr2 = head;
    int val;

    for(int i = 0;i<index-1;i++){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2 = ptr2->next;
    val = ptr2->data;
    ptr2 = ptr2->next;

    ptr1->next = ptr2;
    cout<<"The deleted value is "<<val<<endl;

    return head;

}

node * deleteGivenKey(node * head,int key){

    node *ptr1 = head;
    node *ptr2 = head;
    int ind = -1;
    int temp = 1;

    while(ptr1->next!=NULL){
        if((ptr1->next)->data==key){
            ind = temp;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        temp++;
    }

    if(ind==-1){
        cout<<"The given key is not present in the linked list"<<endl;
        cout<<"So the list remains same and it is -->";
    }

    else{

        ptr2 = ptr2->next;
        ptr2 = ptr2->next;
        ptr1->next = ptr2;
        cout<<"The given key "<<key<<" is deleted and its index is "<<ind<<endl;
    
    }

    return head;
}

node * deleteAfterNode(node *head,node *del){

    node * ptr1 = head;
    node * ptr2 = del;

    while(ptr1->next!=NULL){

        if((ptr1)->data==del->data){
            break;
        }
        ptr1 = ptr1->next;
    }


    int val;
    ptr2 = ptr2->next;
    val = ptr2->data;
    ptr2 = ptr2->next;
    ptr1->next = ptr2;

    cout<<"The deleted element in the linked list is "<<val<<endl;

    return head;
}

node* deleteBeforeNode(node *head,node *del){

    node *ptr1 = head;
    node *ptr2 = del;

    while(((ptr1->next)->next)!=NULL){
        if(((ptr1->next)->next)->data==del->data){ 
            break;
        }

        ptr1 = ptr1->next;
    }

    int val;
    val = (ptr1->next)->data;

    ptr1->next = ptr2;

    cout<<"The element before 110 is deleted and its value is "<<val<<endl;

    return head;
}

node * insertAfterNode(node *head,node *ins,int val){

    node *ptr1 = head;

    node *ins_node;
    ins_node = new node(val);

    while(ptr1->next!=NULL){
        if(ptr1->data==ins->data){
            break;
        }

        ptr1 = ptr1->next;
    }

    ptr1 = ptr1->next;

    ins->next = ins_node;
    ins_node->next = ptr1;

    return head;
}

node * insertBeforeNode(node *head,node * ins,int val){

    node *ptr1 = head;
    node *ptr2 = ins;

    node *ins_node;
    ins_node = new node(val);

    while((ptr1->next)->next!=NULL){
        if((ptr1->next)->data==ins->data){
            break;
        }
        ptr1 = ptr1->next;
    }

    ptr1->next = ins_node;
    ins_node->next = ptr2;

    return head;
}

void deleteNodeWithoutHead(node * &del){

    node *ptr = del;
    ptr = ptr->next;

    del->data = ptr->data;
    del->next = ptr->next;
    
}

void deleteAfterNodeWithoutHead(node * &del){

    node *ptr = del;
    ptr = ptr->next;
    int val;
    val = ptr->data;
    cout<<"The node after is deleted and the deleted value is "<<val<<endl;

    deleteNodeWithoutHead(ptr);
}

void insertAfterNodeWithoutHead(node * &type,int val){

    node *ptr1 = type;
    node *ptr2 = type;
    ptr2 = ptr1->next;

    node * ins_node;
    ins_node = new node(val);

    ptr1->next = ins_node;
    ins_node->next = ptr2;

}

#define linkedListHeader
#endif