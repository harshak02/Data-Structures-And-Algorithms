#include <iostream>

using namespace std;
int arr[20];

int first_data = 0;
int last_data = 19;

void ins_root(int val){
	
	if(arr[0] =='\0'){
		arr[0] = val;
	}
	
	else{
		cout<<"The root is aldready inserted"<<endl;
	}
	
}

void ins_right(int val,int par){
	
	if(arr[par]!= '\0'){
		int temp;
		temp = (2*par)+2;
		arr[temp] = val;
	}
	
	else{
		cout<<"The child is not inserted at right becasue parent is not present at position : "<<par<<endl;
	}
	
}

void ins_left(int val,int par){
	
	if(arr[par]!= '\0'){
		int temp;
		temp = (2*par)+1;
		arr[temp] = val;
	}
	
	else{
		cout<<"The child is not inserted at left becasue parent is not present at position : "<<par<<endl;
	}
	
}

void traversal(){
	
	int i = 0;
	for(i;i<20;i++){
		if(arr[i]!= '\0'){
			cout<<arr[i]<<" ";
		}
		
		else{
			cout<<"_"<<" ";
		}
	}
	
	cout<<endl;
}

int get_root_ind(){

    int temp;
    temp = 0;
    return temp;
}

int get_right_ind(int par){

    int temp = -1;
    if(par >= first_data && ((2*par)+2) <= last_data){

        if(arr[par]!= '\0'){
            temp = 2*(par) + 2;
        }

    }

    return temp;
}

int get_left_ind(int par){

    int temp = -1;
    if(par >= first_data && ((2*par)+1) <= last_data){

        if(arr[par]!= '\0'){
            temp = 2*(par) + 1;
        }

    }

    return temp;
}

void print_root(){

    if(arr[0] == '\0'){
        cout<<"The root of the binary tree is not exist "<<endl;
    }

    else{
        cout<<"The root of the binary tree is "<<arr[0]<<endl;
    }
}

void print_right(int par){

    int temp;
    temp = (2*par)+2;
    if(arr[par]!= '\0' && arr[temp]!= '\0'){
        cout<<"The right child of the parent "<<par<<" is "<<arr[temp]<<endl;
    }

    else if(arr[par] == '\0' && arr[temp]!= '\0'){
        cout<<"The parent "<<par<<" wont exist"<<endl;
    }

    else{
        cout<<"The right child of the parent "<<par<<" is not present"<<endl;
    }
}

void print_left(int par){

    int temp;
    temp = (2*par)+1;
    if(arr[par]!= '\0' && arr[temp]!= '\0'){
        cout<<"The left child of the parent "<<par<<" is "<<arr[temp]<<endl;
    }

    else if(arr[par] == '\0' && arr[temp]!= '\0'){
        cout<<"The parent "<<par<<" wont exist"<<endl;
    }

    else{
        cout<<"The left child of the parent "<<par<<" is not present"<<endl;
    }
}

void preOrder(int ind){

    if(ind >= 0 && arr[ind] != '\0'){

        cout<<arr[ind]<<" ";
        int temp1;
        temp1 = get_left_ind(ind);
        preOrder(temp1);
        int temp2;
        temp2 = get_right_ind(ind);
        preOrder(temp2);

    }
}

void postOrder(int ind){

    if(ind >= 0 && arr[ind] != '\0'){

        int temp1;
        temp1 = get_left_ind(ind);
        postOrder(temp1);
        int temp2;
        temp2 = get_right_ind(ind);
        postOrder(temp2);
        cout<<arr[ind]<<" ";

    }
}

void inOrder(int ind){

    if(ind >= 0 && arr[ind] != '\0'){

        int temp1;
        temp1 = get_left_ind(ind);
        inOrder(temp1);
        cout<<arr[ind]<<" ";
        int temp2;
        temp2 = get_right_ind(ind);
        inOrder(temp2);

    }
}

int getMax(){
	int temp;
	return temp;
}



int getHeight(int ind){
	int temp;

    if(arr[ind] == '\0'){
        temp = -1;
    }

    else{
        int temp1 = 2*ind + 1;
        int left_height = getHeight(temp1);
        int temp2 = 2*ind + 2;
        int right_height = getHeight(temp2);

        if(left_height>=right_height){
            temp = left_height + 1;
        }

        else{
            temp = right_height + 1;
        }
    }

	return temp;
}

int maxi(int a,int b){
    if(a>=b){
        return a;
    }

    else{
        return b;
    }
}

int getDepth(){
	int temp;
	return temp;
}

int main(){
	
	ins_root(10);
	ins_left(20,0);
	ins_right(30,0);
	ins_left(40,1);
	ins_right(50,1);
	ins_right(60,2);
	ins_left(70,4);
	ins_right(80,4);
	ins_left(90,6);
    ins_left(100,9);
	
	traversal();

    preOrder(0);
    cout<<endl;
    inOrder(0);
    cout<<endl;
    postOrder(0);
    cout<<endl;

    int par1 = 4;
    int par2 = 2;

    print_right(4);
    print_left(4);

    print_right(2);
    print_left(2);

	return 0;
}

