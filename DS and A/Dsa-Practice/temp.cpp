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

void traversal(node * ptr){

    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }

    cout<<"NULL"<<endl;
}

void insertAtEnd(node * &head,int val){

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

}

void deleteGivenKey(node * &head,int key){

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
    delete ptr1;
    delete ptr2;

}


int main(){

    int size;
    cout<<"Enter the size of the linked list"<<endl;
    cin>>size;

    node *head = NULL;

    for(int i = 0;i<size;i++){
        int temp;
        cout<<"Enter the "<<i+1<<"th element of the linked list"<<endl;
        cin>>temp;
        insertAtEnd(head,temp);

    }

    cout<<endl;
    traversal(head);
    cout<<endl;

    //deleting the 50 key in the linked list key
    cout<<"The element 50 is being tried to remove from the list"<<endl;
    deleteGivenKey(head,50);
    traversal(head);
    cout<<endl;

    return 0;
}
