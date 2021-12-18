#include<iostream>
using namespace std;

void traversal(int arr[],int size){

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

}


int findPos(int arr[],int size,int key){

    int res = -1;

    for(int i = 0;i<size;i++){
        if(arr[i]==key){
            res = i+1;
            break;
        }
    }

    return res;
}

void insertAtStart(int arr[],int size,int val){

    for(int i = size;i>0;i--){
        arr[i] = arr[i-1];
    }

    arr[0] = val;
}

void insertAtEnd(int arr[],int size,int val){

    arr[size] = val;
}

void InsertAtIndex(int arr[],int size,int val,int index){

    for(int i = size;i>index;i--){
        arr[i] = arr[i-1];
    }

    arr[index] = val;
}

int deleteAtIndex(int arr[],int size,int index){

    int data;
    data = arr[index];

    for(int i = index;i<size-1;i++){
        arr[i] = arr[i+1];
    }

    return data;
}

int deleteAtStart(int arr[],int size){

    int data;
    data = arr[0];

    for(int i = 0;i<size-1;i++){
        arr[i] = arr[i+1];
    }

    return data;
}

int deleteAtEnd(int arr[],int size){

    int data;
    data = arr[size-1];

    return data;
}

void deleteGivenKey(int arr[],int* ptr,int key){

    int data;
    int pos;
    pos = findPos(arr,*ptr,key);

    if(pos==-1){
        cout<<"The given element is not present in the array so cant delete"<<endl;
        cout<<"Therfore the array wont change and it is --> ";
    }

    else{
        pos--;
        deleteAtIndex(arr,*ptr,pos);
        cout<<"The given key "<<key<<" is deleted from the array"<<endl;
        (*ptr)--;

    }

}

int main(){

    int arr[100];
    int size;

    cout<<"Enter the number of elements in the array"<<endl;
    cin>>size;

    int sizeTemp = 0; 

    for(int i = 0;i<size;i++){
        int temp;
        cout<<"Enter the "<<i+1<<"th element of the array"<<endl;
        cin>>temp;
        insertAtEnd(arr,sizeTemp,temp);
        sizeTemp++;
    }

    traversal(arr,sizeTemp);

    int key;
    cout<<"Enter the element to find the position"<<endl;
    cin>>key;

    int post;
    post = findPos(arr,sizeTemp,key);

    if(post==-1){
        cout<<"The given element is not present in the array"<<endl;
    }

    else{
        cout<<"The position of the key "<<key<<" in the array is "<<post<<endl;
    }

    int temp = 100;
    insertAtStart(arr,sizeTemp,temp);
    sizeTemp++;
    cout<<"The element "<<temp<<" is added at the start"<<endl;
    traversal(arr,sizeTemp);

    int temp2 = 110;
    insertAtEnd(arr,sizeTemp,temp2);
    sizeTemp++;
    cout<<"The element "<<temp2<<" is added at the End"<<endl;
    traversal(arr,sizeTemp);

    int val = 120;
    int index = 3;
    InsertAtIndex(arr,sizeTemp,val,index);
    sizeTemp++;
    cout<<"The element "<<val<<" is added to array at index "<<index<<endl;
    traversal(arr,sizeTemp);

    int ind = 4;
    cout<<"The element at the index "<<ind<<" is deleted and its value is "<<deleteAtIndex(arr,sizeTemp,ind)<<endl;
    sizeTemp--;
    traversal(arr,sizeTemp);

    cout<<"The strating element is deleted and its value is "<<deleteAtStart(arr,sizeTemp)<<endl;
    sizeTemp--;
    traversal(arr,sizeTemp);

    cout<<"The Ending element is deleted and its value is "<<deleteAtEnd(arr,sizeTemp)<<endl;
    sizeTemp--;
    traversal(arr,sizeTemp);

    int *ptr;
    ptr = &sizeTemp;

    int keyImp = 20;
    deleteGivenKey(arr,ptr,keyImp);
    traversal(arr,sizeTemp);

    int keyImp2 = 500;
    deleteGivenKey(arr,ptr,keyImp2);
    traversal(arr,sizeTemp);


    return 0;
}
