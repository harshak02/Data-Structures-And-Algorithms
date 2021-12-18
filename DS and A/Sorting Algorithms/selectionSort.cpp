#include<iostream>
using namespace std;

void traversal(int arr[],int size){

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void selectionSort(int arr[],int size){

    int indexMin;

    for(int i=0;i<size-1;i++){
        indexMin = i;

        for(int j = i+1;j<size;j++){
            if(arr[j]<arr[indexMin]){
                indexMin = j;
            }
        }

        int temp;
        temp = arr[i];
        arr[i] = arr[indexMin];
        arr[indexMin] = temp;
    }
}

// void selectionSort(int *A, int n){
//     int indexOfMin, temp;
//     printf("Running Selection sort...\n");
//     for (int i = 0; i < n-1; i++)
//     {
//         indexOfMin = i;
//         for (int j = i+1; j < n; j++)
//         {
//             if(A[j] < A[indexOfMin]){
//                 indexOfMin = j;
//             }
//         }
//         // Swap A[i] and A[indexOfMin]
//         temp = A[i];
//         A[i] = A[indexOfMin];
//         A[indexOfMin] = temp;
//     }
// }

int main(){

    int arr[] = {6,4,3,1,2,5};
    // int arr[] = {12,54,65,7,23,9};
    int size = 6;
    
    traversal(arr,size);
    selectionSort(arr,size);
    traversal(arr,size);

    
    return 0;
}
