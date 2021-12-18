#include<iostream>
using namespace std;

class node{

    public :
    int data;
    node * prev;
    node * next;

    node(int val){
        data = val;
    }

};

node *head = NULL;

void traversal(){

    node * ptr = head;
    while(ptr->next!=head){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    cout<<ptr->data<<endl;
    cout<<endl;
}

node *insertAtEnd(int val){

    node *ins_node;
    ins_node = new node(val);
    node *ptr = head;
    node *ptr2 = head;

    if(head==NULL){
        head = ins_node;
        ins_node->next = head;
        ins_node->prev = head;
    }

    else{

        while(ptr->next!=head){
        ptr = ptr->next;
        }
        ptr->next = ins_node;
        ins_node->prev = ptr;
        ins_node->next = ptr2;

    }

    return head;
}

node *insertAtStart(int val){

    node *ins_node;
    ins_node = new node(val);
    node *ptr = head;
    node *ptr2 = head;

    if(head==NULL){
        head = ins_node;
        ins_node->next = head;
        ins_node->prev = head;
    }

    else{

        while(ptr2->next!=head){
            ptr2 = ptr2->next;
        }
        ins_node->prev = ptr2;
        head->prev = ins_node;
        ins_node->next = head;
        ptr2->next = ins_node;
        head = ins_node;
    }

    return head;
}

node *insertAtIndex(int ind,int val){

    node *ins_node;
    ins_node = new node(val);
    node *ptr = head;
    node *ptr2 = head;

    for(int i = 0;i<ind-1;i++){
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr2 = ptr2->next;
    ins_node->next = ptr2;
    ins_node->prev = ptr;
    ptr2->prev = ins_node;
    ptr->next = ins_node;

    return head;
}

int deleteAtStart(){
    
    node *ptrdel = head;
    node *ptr2 = head;
    node *ptr1 = head->next;

    while(ptr2->next!=head){
        ptr2 = ptr2->next;
    }

    int val;
    val = ptrdel->data;
    ptr2->next = ptr1;
    ptr1->prev = ptr2;
    head = ptr1;

    delete ptrdel;

    return val;

}

int deleteAtEnd(){

    node *ptrdel = head;
    node *ptr1 = head;
    node *ptr2 = head;

    while(ptrdel->next!=head){
        ptrdel = ptrdel->next;
    }

    int val;
    val = ptrdel->data;
    ptr1 = ptrdel->prev;
    ptr2 = ptrdel->next;

    ptr1->next = ptr2;
    ptr2->prev = ptr1;

    delete ptrdel;

    return val;

}

int deleteAtIndex(int ind){

    int val;
    node *ptrdel = head;
    node *ptr1 = head;
    node *ptr2 = head;

    for(int i = 0;i<ind;i++){
        ptrdel = ptrdel->next;
    }

    ptr2 = ptrdel->next;
    ptr1 = ptrdel->prev;
    val = ptrdel->data;

    ptr1->next = ptr2;
    ptr2->prev = ptr1;
    delete ptrdel;

    return val;
}

int deleteGivenKey(int key){

    node *ptrdel = head;
    node *ptr1 = head;
    node *ptr2 = head;
    int ind = 1;

    while(ptrdel->data!=key){
        ptrdel = ptrdel->next;
        ind++;
    }

    ptr1 = ptrdel->prev;
    ptr2 = ptrdel->next;

    ptr1->next = ptr2;
    ptr2->prev = ptr1;

    return ind;
    
}

int main(){

    int size;
    cout<<"Enter the size of the doubly circular linked list"<<endl;
    cin>>size;

    for(int i = 0;i<size;i++){
        int temp;
        cout<<"Enter the element no. :"<<i+1<<endl;
        cin>>temp;
        head = insertAtStart(temp);
    }
    traversal();

    head = insertAtIndex(2,100);
    traversal();

    cout<<"The element at start is deleted and it is :"<<deleteAtStart()<<endl;
    traversal();

    cout<<"The element at end is deleted and it is :"<<deleteAtEnd()<<endl;
    traversal();

    int ind = 2;
    cout<<"The element at index "<<ind<<" is deleted and it is :"<<deleteAtIndex(ind)<<endl;
    traversal();

    int key = 2;
    cout<<"The key "<<key<<" is deleted and it is present at "<<deleteAtIndex(ind)<<endl;
    traversal();

    return 0;
}
