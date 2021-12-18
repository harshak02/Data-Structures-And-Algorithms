#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class node{
	public:
	int data;
	node* link;
	
	
}; node* top=0;

int push(){
	int n;
	cout<<"Enter element to insert: ";
	cin>>n;
	node* newnode = new node();
	if(!newnode){
		cout<<"\nHeap Overflow";
        exit(1);
	}

    if(newnode==NULL){

        top = newnode;
    }

    else{

	    newnode->data =n;
	    newnode->link = top;
	    top = newnode;
    }

	return 0;
}
void display(){
	node* temp= top;
	if(temp == 0)
	   {
	   	cout<<"stack is empty"<<endl;
	   	return;
	   }
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp= temp->link;
	}
	cout<<endl;
}
int isempty()
{
    return top == NULL;
}
int peek(){
	if(!isempty){
	 	 return(top->data);
	 
   }
	else
        exit(1);
}
void pop(){
	node* temp ;
	if(temp==0){
		cout<<"stack is underflow"<<endl;
	    exit(1);
	}
	else{
		temp = top;
		top = top->link;
		delete temp;
	}
}
int size(){
	int count = 0;
	node* temp = top;
	while(temp!=0){
		temp= temp->link;
		count++;	
	}
	return(count);
}
int main(int argc, char** argv) {
	
    int ch;
	while(ch!=7){

	    cout<<"1.Push\n2.Pop\n3.Traverse\n4.Peek\n5.Size\n6.Index\n7.Exit\n";
	    cout<<"Enter your choice: ";
        cin>>ch;
		switch(ch){
			case 1: cout<<push();
			        display();
			        break;

			case 2: pop();
				     display();
			       	 break;

			case 3: display();
			        break;

			case 4: cout << "Top element is: "<<peek();
			        
			        break;

			case 5: cout<<"size of stack is: "<< size();
			       
			        break;
			case 6: 
			       break;

			case 7: exit(1);
			
			}        
		}
	
	
	return 0;
}
