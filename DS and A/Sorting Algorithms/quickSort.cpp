#include<iostream>
using namespace std;

void traversal(int arr[],int size){

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int partition(int arr[],int low,int high){

    int pivot;
    pivot = arr[low];
    int i = low+1;
    int j = high;

    do{

    while(arr[i]<=pivot){
        i++;
    }

    while(arr[j]>pivot){
        j--;
    }

    if(i<j){

    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    }
    
    }while(i<j);

    int temp;
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;

}

void quickSort(int arr[],int low,int high,int size){

    int index;

    if(low<high){

    index = partition(arr,low,high);
    traversal(arr,size);
    quickSort(arr,low,index-1,size);
    quickSort(arr,index+1,high,size);

    }

}

int main(){
    
    int arr[] = {6,5,9,4,1,7,8,2,3};
    // int arr[] = {12,54,65,7,23,9};
    int size = 9;
    int low = 0;
    int high = size-1;
    
    traversal(arr,size);
    quickSort(arr,low,high,size);
    traversal(arr,size);

    return 0;
}
