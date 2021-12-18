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

// void insertAtStart(node * &head,int val){

//     node *ptr = head;
//     node * ins_node;
//     ins_node = new node(val);


//     if(head==NULL){

//         head = ins_node;  
//     }

//     else{
//         ins_node->next = head;
//         head = ins_node;
//     }

// }

// void insertAtIndex(node * &head,int val,int index){

//     node *ptr1 = head;
//     node *ptr2 = head;
//     node * ins_node;
//     ins_node = new node(val);

//     for(int i = 0;i<index-1;i++){
//        ptr1 = ptr1->next; 
//        ptr2 = ptr2->next; 
//     }

//     ptr2 = ptr2->next;
    
//     ptr1->next = ins_node;
//     ins_node->next = ptr2;

// }

// int findPos(node * head,int key){

//     int res = -1;
//     int i = 1;
//     node *ptr = head;

//     while(ptr!=NULL){

//         if(ptr->data==key){
//             res = i;
//             break;
//         }
//         i++;
//         ptr = ptr->next;
//     }

//     return res;
// }

// void deleteAtStart(node * &head){

//     node *ptr = head;
//     int val;
//     val = ptr->data;
//     ptr = ptr->next;
//     head = ptr;
//     delete ptr;

//     cout<<"The deleted value is "<<val<<endl;

// }

// void  deleteAtEnd(node * &head){

//     node *ptr1 = head;
//     node *ptr2 = head;
//     int val;

//     while((ptr1->next)->next!=NULL){
//         ptr1 = ptr1->next;
//         ptr2 = ptr2->next;
//     }

//     ptr2 = ptr2->next;
//     val = ptr2->data;
//     ptr1->next = NULL;

//     cout<<"The deleted value is "<<val<<endl;
//     delete ptr2;
//     delete ptr1;

// }


// void deleteAtIndex(node * &head,int index){

//     node *ptr1 = head;
//     node *ptr2 = head;
//     int val;

//     for(int i = 0;i<index-1;i++){
//         ptr1 = ptr1->next;
//         ptr2 = ptr2->next;
//     }
//     ptr2 = ptr2->next;
//     val = ptr2->data;
//     ptr2 = ptr2->next;

//     ptr1->next = ptr2;
//     cout<<"The deleted value is "<<val<<endl;
//     delete ptr2;
//     delete ptr1;

// }

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

// void deleteAfterNode(node * &head,node *del){

//     node * ptr1 = head;
//     node * ptr2 = head;

//     while(ptr1->next!=NULL){

//         if((ptr1)->data==del->data){
//             break;
//         }
//         ptr1 = ptr1->next;
//         ptr2 = ptr2->next;
//     }

//     ptr2 = ptr2->next;
//     int val;
//     val = ptr2->data;
//     ptr2 = ptr2->next;

//     ptr1->next = ptr2;

//     cout<<"The deleted element in the linked list is "<<val<<endl;

// }

// void deleteBeforeNode(node *head){
    
// }

// void insertAfterNode(node *head,int val){

// }

// void insertBeforeNode(node*head,int val){

// }



// void deleteAfterNodeWithoutHead(node *type){

// }

// void deleteBeforeNodeWithoutHead(node *type){

// }

// void insertAfterNodeWithoutHead(node *type,int val){

// }

// void insertBeforeNodeWithoutHead(node*type,int val){

// }

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

    // //takes 100 from start
    // insertAtStart(head,100);
    // cout<<"The 100 element is inserted at the start"<<endl;
    // traversal(head);
    // cout<<endl;

    // //takes 110 at index 3
    // insertAtIndex(head,110,3);
    // cout<<"The 110 element is inserted at the index 3"<<endl;
    // traversal(head);
    // cout<<endl;

    // //finding the index of the key 40
    // int temp1;
    // cout<<"Finding the position of the key 40"<<endl;
    // temp1 = findPos(head,40);

    // if(temp1==-1){
    //     cout<<"The given key is not present in the linked list"<<endl;
    // }

    // else{
    //     cout<<"The key 40 is present at "<<temp1<<" position"<<endl;
    // }

    // cout<<endl;

    // //finding the index of the key 300
    // int temp2;
    // cout<<"Finding the position of the key 300"<<endl;
    // temp2 = findPos(head,300);

    // if(temp2==-1){
    //     cout<<"The given key is not present in the linked list"<<endl;
    // }

    // else{
    //     cout<<"The key 40 is present at "<<temp2<<" position"<<endl;
    // }

    // cout<<endl;

    // //deleting the starting Element
    // cout<<"The element at starting is deleted"<<endl;
    // deleteAtStart(head);
    // traversal(head);
    // cout<<endl;

    //deleting the Ending Element
    // cout<<"The element at the end is deleted"<<endl;
    // deleteAtEnd(head);
    // traversal(head);
    // cout<<endl;

    // //deleting the element in the linked list at index 3
    // cout<<"The element at the index 3 in the linked list is deleted"<<endl;
    // deleteAtIndex(head,3);
    // traversal(head);
    // cout<<endl;

    //deleting the 50 key in the linked list key
    cout<<"The element 50 is being tried to remove from the list"<<endl;
    deleteGivenKey(head,50);
    traversal(head);
    cout<<endl;

    // //deleting the 2000 key in the linked list key
    // cout<<"The element 2000 is being tried to remove from the list"<<endl;
    // deleteGivenKey(head,2000);
    // traversal(head);
    // cout<<endl;

    // //delete after a node 110
    // cout<<"The node after 110 is being deleted"<<endl;
    // node *temp = head;
    // for(int i = 0;i<2;i++){
    //     temp = temp->next;
    // }
    // deleteAfterNode(head,temp);
    // traversal(head);

    return 0;
}
