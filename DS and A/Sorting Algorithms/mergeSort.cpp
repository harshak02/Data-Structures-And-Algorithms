#include<iostream>
using namespace std;

void traversal(int arr[],int size){

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void mergeSort (int arr1[],int arr2[],int arr3[],int size1,int size2,int size3){

    int i = 0;
    int j = 0;
    int k = 0;

    while(i<size1 && j<size2){

        if(arr1[i]>=arr2[j]){
            arr3[k] = arr2[j];
            j++;
        }

        else{
            arr3[k] = arr1[i];
            i++;
        }

        k++;
    }

    if(i>=size1){
        while(j<size2){
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }

    else{
        while(i<size1){
            arr3[k] = arr1[i];
            k++;
            i++;
        }
    }
}


int main(){

    int arr1[] = {7,9,18,19,22};
    int arr2[] = {1,6,9,11};

    int size1 = 5;
    int size2 = 4;
    int size3 = 9;

    int arr3[9];

    mergeSort(arr1,arr2,arr3,size1,size2,size3);
    traversal(arr3,size3);

    
    return 0;
}
