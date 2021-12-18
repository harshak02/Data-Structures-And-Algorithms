#include<iostream>
using namespace std;

void traversal(int arr[],int size){

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void insertionSort(int arr[],int size){

    for(int i = 1;i<=size-1;i++){// compuslory start with 1
        int key;
        key = arr[i];
        int j = i-1;

        while(arr[j]>key && j>=0){

            arr[j+1] = arr[j];

            j--;
        }

        arr[j+1] = key;
    }
}

int main(){

    int arr[] = {12,54,65,7,23,9};
    int size = 6;
    
    traversal(arr,size);
    insertionSort(arr,size);
    traversal(arr,size);

    return 0;
}