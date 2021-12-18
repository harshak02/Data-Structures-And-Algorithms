#include<iostream>
using namespace std;

int arr[20];

void ins_root(int val){

    if(arr[0] == '\0'){
        arr[0] = val;
    }

    else{
        cout<<"The root is aldready fixed"<<endl;
    }
}

void putLeft(int par,int data){

    if(arr[par]=='\0'){
        cout<<"The child cannot be inserted at left because there is no parent at "<<par<<endl;
    }

    else{
        arr[(2*par)+1] = data;
    }
}

void putRight(int par,int data){

    if(arr[par]=='\0'){
        cout<<"The child cannot be inserted at right because there is no parent at "<<par<<endl;
    }

    else{
        arr[(2*par)+2] = data;
    }
}



void traversal(){

    for(int i = 0;i<20;i++){

        if(arr[i] != '\0'){
            cout<<arr[i]<<" ";
        }

        else{
            cout<<"_"<<" ";
        }
    }

    cout<<endl;

}

void preOrder(){

}

void postOrder(){

}

void inOrder(){

}

int main(){

    ins_root(10);
    putLeft(0,20);
    putRight(0,30);
    putRight(1,40);
    putLeft(4,50);
    putRight(4,60);

    traversal();

    return 0;
}
