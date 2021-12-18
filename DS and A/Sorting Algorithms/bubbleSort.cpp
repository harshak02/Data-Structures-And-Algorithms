#include<iostream>
using namespace std;

void traversal(int arr[],int size){

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void bubbleSort(int arr[],int size){

    for(int i = 0;i<size-1;i++){
        for(int j = 0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSortAdv(int arr[],int size){

    int isSorted;
    int k = 0;

    for(int i = 0;i<size-1;i++){

        isSorted = 1;
        for(int j = 0;j<size-i-1;j++){

            if(arr[j]>arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                isSorted = 0;
    
            }
        }

        if(isSorted){
            cout<<"The array is sorted"<<endl;
            break;
        }
        cout<<"Worked for the "<<k+1<<"th pass"<<endl;
        k++;
    }
}

int main(){

    // int arr[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    // int size = 11;
    int arr[] = {6,2,3,4,5,1};
    int size = 6;
    
    traversal(arr,size);
    bubbleSortAdv(arr,size);
    traversal(arr,size);

    
    return 0;
}
