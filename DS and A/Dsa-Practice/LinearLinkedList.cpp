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

void isEmpty(node *head){

    node *ptr = head;

    if(ptr==NULL){
        cout<<"The Given linked list is Empty"<<endl;
    }

    else{
        cout<<"The given linked list is not empty"<<endl;
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
    delete ptr;

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
    delete ptr2;
    delete ptr1;

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
    delete ptr2;
    delete ptr1;

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
    delete ptr1;
    delete ptr2;

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

int main(){

    int size;
    cout<<"Enter the size of the linked list"<<endl;
    cin>>size;

    node *head = NULL;

    for(int i = 0;i<size;i++){
        int temp;
        cout<<"Enter the "<<i+1<<"th element of the linked list"<<endl;
        cin>>temp;
        head = insertAtEnd(head,temp);

    }

    //Displaying the linked list elements
    cout<<endl;
    traversal(head);
    cout<<endl;

    //Finding the size of the linked list
    int len;
    len = sizeOfLinkedList(head);
    cout<<"The size of the linked list is "<<len<<endl;
    cout<<endl;

    //Finding the nth index element-->here we find 5th index element
    int value;
    int index = 4;
    value = findNthIndexElement(head,index);
    cout<<"The value of the data at the "<<index<<" is "<<value<<endl;
    cout<<endl;

    //takes 100 from start
    head = insertAtStart(head,100);
    cout<<"The 100 element is inserted at the start"<<endl;
    traversal(head);
    cout<<endl;

    //takes 110 at index 3
    head = insertAtIndex(head,110,3);
    cout<<"The 110 element is inserted at the index 3"<<endl;
    traversal(head);
    cout<<endl;

    //finding the index of the key 40
    int temp1;
    cout<<"Finding the position of the key 40"<<endl;
    temp1 = findPos(head,40);

    if(temp1==-1){
        cout<<"The given key is not present in the linked list"<<endl;
    }

    else{
        cout<<"The key 40 is present at "<<temp1<<" position"<<endl;
    }

    cout<<endl;

    //finding the index of the key 300
    int temp2;
    cout<<"Finding the position of the key 300"<<endl;
    temp2 = findPos(head,300);

    if(temp2==-1){
        cout<<"The given key is not present in the linked list"<<endl;
    }

    else{
        cout<<"The key 40 is present at "<<temp2<<" position"<<endl;
    }

    cout<<endl;

    //deleting the starting Element
    cout<<"The element at starting is deleted"<<endl;
    head = deleteAtStart(head);
    traversal(head);
    cout<<endl;

    //deleting the Ending Element
    cout<<"The element at the end is deleted"<<endl;
    deleteAtEnd(head);
    traversal(head);
    cout<<endl;

    //deleting the element in the linked list at index 3
    cout<<"The element at the index 3 in the linked list is deleted"<<endl;
    head = deleteAtIndex(head,3);
    traversal(head);
    cout<<endl;

    //deleting the 50 key in the linked list key
    cout<<"The element 50 is being tried to remove from the list"<<endl;
    head = deleteGivenKey(head,50);
    traversal(head);
    cout<<endl;

    //deleting the 2000 key in the linked list key
    cout<<"The element 2000 is being tried to remove from the list"<<endl;
    head = deleteGivenKey(head,2000);
    traversal(head);
    cout<<endl;

    //delete after a node 110
    cout<<"The node after 110 is being deleted"<<endl;
    node *temp = head;
    for(int i = 0;i<2;i++){
        temp = temp->next;
    }
    head = deleteAfterNode(head,temp);
    traversal(head);
    cout<<endl;

    //delete before a node 110
    cout<<"The node before 110 is being deleted"<<endl;
    node *temp4 = head;
    //traversing to the node 110
    for(int i = 0;i<2;i++){
        temp4 = temp4->next;
    }
    head = deleteBeforeNode(head,temp4);
    traversal(head);
    cout<<endl;

    //insert after node 110
    cout<<"The node after 110 is being inserted and the inserted value is 120"<<endl;
    node *temp5 = head;
    //traversing to the node 110
    for(int i =0;i<1;i++){
        temp5 = temp5->next;
    }
    head = insertAfterNode(head,temp5,120);
    traversal(head);
    cout<<endl;

    //insert before node 110 
    cout<<"The node before 110  is being inserted and the inserted value is 120"<<endl;
    node *temp6 = head;
    //traversing to the node 110
    for(int i =0;i<1;i++){
        temp6 = temp6->next;
    }
    head = insertBeforeNode(head,temp6,130);
    traversal(head);
    cout<<endl;

    //Deleting node  110 without passing head
    cout<<"The node 110 is deleted without passing head as variable"<<endl;
    node *temp7 = head;
    //traversing to the node 110
    for(int i =0;i<2;i++){
        temp7 = temp7->next;
    }
    cout<<"The node 110 is deleted"<<endl;
    deleteNodeWithoutHead(temp7);
    traversal(head);
    cout<<endl;

    //insert after node 130 without passing head
    cout<<"The node after 130 is being inserted and the inserted value is 150"<<endl;
    node *temp9 = head;
    //traversing to the node 130
    for(int i =0;i<1;i++){
        temp9 = temp9->next;
    }
    insertAfterNodeWithoutHead(temp9,150);
    traversal(head);
    cout<<endl;

    //Deleting node after 130 without passing head
    cout<<"The node after 130 is deleted without passing head as variable"<<endl;
    node * temp10 = head;
    //traversing to the node 130
    for(int i =0;i<1;i++){
        temp10 = temp10->next;
    }
    deleteAfterNodeWithoutHead(temp10);
    traversal(head);
    cout<<endl;

    return 0;
}
