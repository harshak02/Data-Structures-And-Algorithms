#include<iostream>
#include<string.h>
#include "nodeDeclaration.h"
#include "linkedListheader.h"
#include "stackListHeader.h"
#include "queueListHeader.h"
using namespace std;

int main(){

    char imp;
    string str1 = "Enter '1' for the Linked List";
    string str2 = "Enter '2' for the Stack using linked list";
    string str3 = "Enter '3' for the Queue using linked List";

    cout<<"Enter the choice"<<endl;
    cin>>imp;

    if(imp == '1'){
        int size;
        cout<<"Enter the size of the linked list"<<endl;
        cin>>size;

        for(int i = 0;i<size;i++){
            int temp;
            cout<<"Enter the element no. : "<<i+1<<endl;
            cin>>temp;
            head = insertAtEnd(head,temp);
        }

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
                traversal(head);
                cout<<endl;
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

    }

    else if(imp == '2'){

        if(isEmptyS()){

            cout<<"The stack is Empty"<<endl;
        }

        push(10);
        push(20);
        push(30);
        push(40);
        push(50);
        push(60);
        traversal();
    
        if(isFullS()){
            cout<<"the stack is Overflown"<<endl;
        }
    
        else{
            cout<<"The stack is not full"<<endl;
        }
    
        cout<<"The element in the stcak is popped and it is "<<pop()<<endl;
        cout<<"The element in the stcak is popped and it is "<<pop()<<endl;
    
        int val;
        int ind = 3;
        val = peek(3);
        cout<<"The value of the 3rd position element from top is "<<val<<endl;
    
        cout<<"The size of the stack is "<<sizeOfstack()<<endl;
    
        cout<<"The bottom most Element of the stack is "<<stackBottom()<<endl;
    
        cout<<"The top most Element of the stack is "<<stackTop()<<endl;
    
        push(100);
        push(110);
    
        traversal();
    
        int temp1;
        temp1 = valueAtIndex(3);//this is from the start and gives index but not position;
        cout<<"The value of the 3rd index element is "<<temp1<<endl;
    
        int temp2;
        temp2 = indexOfValue(100);//this gives the index of the given value her it is 1000;
        cout<<"The index of the 100 from the start is "<<temp2<<endl;

        traversal();
        cout<<endl;
        cout<<endl;

        cout<<"Using linked list Functions in stacks"<<endl;

        cout<<endl;
        cout<<endl;

        string s1 = "Enter 1 for size of the stack";
        string s2 = "Enter 2 for finding nth index element";
        string s3 = "Enter 3 for reversing stack";
        string s4 = "Enter 4 for insert at index";
        string s5 = "Enter 5 for finding index of element";
        string s6 = "Enter 6 for delete at index";
        string s7 = "Enter 7 for delete given key excluding first and last";
        string s8 = "Enter 8 for inserting after a node";
        string s9 = "Enter 9 for deleting after a node";
        string s10 = "Enter 10 for inserting before a node";
        string s11 = "Enter 11 for deleting before a node";
        string s12 = "Enter 12 for deleting a node without head";
        string s13 = "Enter 13 for deleting a node after without head";
        string s14 = "Enter 14 for insering a node after without head";
        string s15 = "Enter 15 for exiting";

        char imp2;

        while(1){

            cout<<s1<<endl;cout<<s2<<endl;cout<<s3<<endl;cout<<s4<<endl;cout<<s5<<endl;
            cout<<s6<<endl;cout<<s7<<endl;cout<<s8<<endl;cout<<s9<<endl;cout<<s10<<endl;
            cout<<s11<<endl;cout<<s12<<endl;cout<<s13<<endl;cout<<s14<<endl;

            cin>>imp2;

            if(imp2=='1'){
                int size;
                size = sizeOfLinkedList(top);
                cout<<"The size of the given linked list is "<<size<<endl;
                cout<<endl;
            }

            else if(imp2=='2'){
                int temp1;
                cout<<"Enter the index to find the value at that index"<<endl;
                cin>>temp1;
                int temp2;
                temp2 = findNthIndexElement(top,temp1);
                cout<<"The value at the index "<<temp1<<" is "<<temp2<<endl;
                cout<<endl;
            }

            else if(imp2=='3'){
                top = reverse(top);
                traversal(top);
                cout<<endl;
            }

            else if(imp2=='4'){
                int temp6;
                cout<<"Enter the index at which node is isnerted"<<endl;
                cin>>temp6;
                int temp5;
                cout<<"Enter the node to get inserted at ending"<<endl;
                cin>>temp5;
                top = insertAtIndex(top,temp5,temp6);
                traversal(top);
                cout<<endl;                
            }

            else if(imp2=='5'){
                break;
            }

        }


    
    }
    
    
    return 0;
}
