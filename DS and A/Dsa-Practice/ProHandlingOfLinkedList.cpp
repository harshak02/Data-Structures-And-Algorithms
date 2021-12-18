#include<iostream>
#include<string>
using namespace std;

class node{

    public :

    int data;
    node * next;

    node(int val){
        data = val;
        next = NULL;
    }

    node(){

    }

};

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

int main(){

    int size;
    cout<<"Enter the size.... to create a linked list"<<endl;
    cin>>size;

    for(int i = 0;i<size;i++){
        int temp;
        cout<<"Enter the element no. "<<i+1<<endl;
        cin>>temp;
        head = insertAtEnd(head,temp);
    }

    cout<<"The linked list is created... and it is "<<endl;
    traversal(head);
    cout<<endl;

    string str = "\n***************SELECT THE OPTION TO PERFORM WITH LINKED LIST********************\n\n";

    string str0 = "Enter No '0' for -> Displaying the linked list";
    string str1 = "Enter No '1' for -> finding whether list is empty or not";
    string str2 = "Enter No '2' for -> finding the size of the list";
    string str3 = "Enter No '3  for -> finding the element present at nth index ";
    string str4 = "Enter No '4' for -> Inserting node at starting";
    string str5 = "Enter No '5' for -> Inserting node at the ending";
    string str6 = "Enter No '6' for -> Inserting node at the specified index";
    string str7 = "Enter No '7' for -> Deleting the starting node";
    string str8 = "Enter No '8' for -> Deleting the ending node";
    string str9 = "Enter No '9' for -> Deleting the node at the specified index";
    string str10 = "Enter No '10' for -> Deleting the given key from the list";
    string str11 = "Enter No '11' for -> Inserting an element after a node";
    string str12 = "Enter No '12' for -> Inserting an element before a node";
    string str13 = "Enter No '13' for -> Deleteing a node before a specified node";
    string str14 = "Enter No '14' for -> Deleting a node after a specified node";
    string str15 = "Enter No '15' for -> Deleting a given node without passing head reference";
    string str16 = "Enter No '16' for -> Deleting a node after the specified node without passing head reference";
    string str17 = "Enter No '17' for -> Inserting a node after the specified node without passing head reference";
    string str18 = "Enter No '18' for -> Reversing the linked list";
    string str20 = "Enter No '19' for -> Checking the linked list is Full or Not";
    string str19 = "Enter Key 'E' for -> To exit the operations";

    while(1){
        cout<<str<<endl;cout<<str0<<endl;cout<<str1<<endl;cout<<str2<<endl;cout<<str3<<endl;
        cout<<str4<<endl;cout<<str5<<endl;cout<<str6<<endl;cout<<str7<<endl;cout<<str8<<endl;
        cout<<str9<<endl;cout<<str10<<endl;cout<<str11<<endl;cout<<str12<<endl;cout<<str13<<endl;
        cout<<str14<<endl;cout<<str15<<endl;cout<<str16<<endl;cout<<str17<<endl;cout<<str18<<endl;
        cout<<str20<<endl;cout<<str19<<endl;

        cout<<"Enter your choice"<<endl;
        string ch;
        cin>>ch;

        if(ch=="0"){
            traversal(head);
            cout<<endl;
        }

        else if(ch=="1"){
            if(isEmpty(head)){
                cout<<"The linked list is empty"<<endl;
            }

            else{
                cout<<"The linked list is not empty"<<endl;
            }
            cout<<endl;
        }

        else if(ch=="2"){
            int size;
            size = sizeOfLinkedList(head);
            cout<<"The size of the given linked list is "<<size<<endl;
            cout<<endl;
        }

        else if(ch=="3"){
            int temp1;
            cout<<"Enter the index to find the value at that index"<<endl;
            cin>>temp1;
            int temp2;
            temp2 = findNthIndexElement(head,temp1);
            cout<<"The value at the index "<<temp1<<" is "<<temp2<<endl;
            cout<<endl;
        }

        else if(ch=="4"){
            int temp3;
            cout<<"Enter the node to get inserted at start"<<endl;
            cin>>temp3;
            head = insertAtStart(head,temp3);
            traversal(head);
            cout<<endl;
        }

        else if(ch=="5"){
            int temp4;
            cout<<"Enter the node to get inserted at ending"<<endl;
            cin>>temp4;
            head = insertAtEnd(head,temp4);
            traversal(head);
            cout<<endl;
        }

        else if(ch=="6"){
            int temp6;
            cout<<"Enter the index at which node is isnerted"<<endl;
            cin>>temp6;
            int temp5;
            cout<<"Enter the node to get inserted at ending"<<endl;
            cin>>temp5;
            head = insertAtIndex(head,temp5,temp6);
            traversal(head);
            cout<<endl;
        }

        else if(ch=="7"){

            if(isEmpty(head)){
                cout<<"The linked list is Empty"<<endl;
                break;
            }

            else{
                head = deleteAtStart(head);
            }

            traversal(head);

        }


        else if(ch=="8"){

            if(isEmpty(head)){
                cout<<"The linked list is Empty"<<endl;
                break;
            }

            else{
                head = deleteAtEnd(head);
            }

            traversal(head);

        }

        else if(ch=="9"){

            if(isEmpty(head)){
                cout<<"The linked list is Empty"<<endl;
                break;
            }

            else{
                int temp7;
                cout<<"Enter the specified index of node to get deleted"<<endl;
                cin>>temp7;
                head = deleteAtIndex(head,temp7);
            }

            traversal(head);

        }

        else if(ch == "10"){

            if(isEmpty(head)){
                cout<<"The linked list is Empty"<<endl;
                break;
            }

            else{
                int temp8;
                cout<<"Enter the specified key to get deleted"<<endl;
                cin>>temp8;
                head = deleteGivenKey(head,temp8);
            }

            traversal(head);

        }

        else if(ch=="11"){

            int temp10;
            cout<<"Enter the node after which new value is insserted"<<endl;
            cin>>temp10;

            int temp9;
            cout<<"Enter the value to get inserted"<<endl;
            cin>>temp9;

            node *ptrTemp = head;
            while(ptrTemp!=NULL){
                if(ptrTemp->data==temp10){
                    break;
                }
                ptrTemp = ptrTemp->next;
            }

            head = insertAfterNode(head,ptrTemp,temp9);
            traversal(head);

        }

        else if(ch=="12"){

            int temp11;
            cout<<"Enter the node before which new value is insserted"<<endl;
            cin>>temp11;

            int temp9;
            cout<<"Enter the value to get inserted"<<endl;
            cin>>temp9;

            node *ptrTemp = head;
            while(ptrTemp!=NULL){
                if((ptrTemp->next)->data==temp11){
                    break;
                }
                ptrTemp = ptrTemp->next;
            }

            head = insertAfterNode(head,ptrTemp,temp9);
            traversal(head);

        }

        else if(ch=="13"){

            if(isEmpty(head)){
                cout<<"The linked list is Empty"<<endl;
            }

            else{

                int temp11;
                cout<<"Enter the node before which a node is deleted"<<endl;
                cin>>temp11;


                node *ptrTemp = head;
                while(ptrTemp!=NULL){
                    if((ptrTemp->next)->data==temp11){
                        break;
                    }
                    ptrTemp = ptrTemp->next;
                }

                head = deleteBeforeNode(head,ptrTemp);
                traversal(head);

            }

        }

        else if(ch=="14"){

            if(isEmpty(head)){
                cout<<"The linked list is Empty"<<endl;
            }

            else{

                int temp11;
                cout<<"Enter the node after which a node is deleted"<<endl;
                cin>>temp11;
    
    
                node *ptrTemp = head;
                while(ptrTemp!=NULL){
                    if((ptrTemp)->data==temp11){
                        break;
                    }
                    ptrTemp = ptrTemp->next;
                }
    
                head = deleteAfterNode(head,ptrTemp);
                traversal(head);

            }

        }

        else if(ch == "15"){

            if(isEmpty(head)){
                cout<<"The linked list is Empty"<<endl;
            }

            else{

                int temp11;
                cout<<"Enter the node to get deleted without passing head reference"<<endl;
                cin>>temp11;

                node *ptrTemp = head;

                while(ptrTemp!=NULL){
                    if(ptrTemp->data==temp11){
                        break;
                    }
                    ptrTemp = ptrTemp->next;
                }

                deleteNodeWithoutHead(ptrTemp);
                traversal(head);
            }
        }

        else if(ch == "16"){

            if(isEmpty(head)){
                cout<<"The linked list is Empty"<<endl;
            }

            else{

                int temp12;
                cout<<"Enter the node after which a node to get deleted without passing head reference"<<endl;
                cin>>temp12;

                node *ptrTemp = head;

                while(ptrTemp!=NULL){
                    if((ptrTemp->next)->data==temp12){
                        break;
                    }
                    ptrTemp = ptrTemp->next;
                }

                ptrTemp = ptrTemp->next;

                deleteAfterNodeWithoutHead(ptrTemp);
                traversal(head);
            }
        }

        else if(ch == "17"){

            int temp12;
            cout<<"Enter the node after which a node to get inserted without passing head reference"<<endl;
            cin>>temp12; 

            int temp13;
            cout<<"Enter the value to get insrted"<<endl;
            cin>>temp13;

            node *ptrTemp = head; 
            while(ptrTemp!=NULL){
                if((ptrTemp->next)->data==temp12){
                    break;
                }
                ptrTemp = ptrTemp->next;

            }
            ptrTemp = ptrTemp->next;

            insertAfterNodeWithoutHead(ptrTemp,temp13);
            traversal(head);

        }

        else if(ch == "18"){
            head = reverse(head);
        }

        else if(ch == "19"){

            int temp;
            temp = isFull(head);

            if(temp==1){
                cout<<"The linked list is full"<<endl;
            }

            else{
                cout<<"The linked list not full"<<endl;
            }

        }

        else if(ch == "E"){
            break;
        }

        else{
            cout<<"Please Enter a valid choice"<<endl;
        }

        cout<<endl;
    

    }

    cout<<"Succesfully exited the linked list and its operations"<<endl;

    return 0;
}
