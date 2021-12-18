#include<iostream>
using namespace std;

void traversal(int arr[],int size){

    for(int i = 0;i<(size);i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void merge(int arr1[],int low,int high,int mid){

    int arr2[100];
    int i = low;
    int j = mid+1;
    int k = low;

    while(i<=mid && j<=high){

        if(arr1[i]>=arr1[j]){
            arr2[k] = arr1[j];
            j++;
        }

        else{
            arr2[k] = arr1[i];
            i++;
        }

        k++;
    }

    if(i>=mid+1){
        while(j<=high){
            arr2[k] = arr1[j];
            k++;
            j++;
        }
    }

    else{
        while(i<=mid){
            arr2[k] = arr1[i];
            k++;
            i++;
        }
    }

    for(int i = 0;i<=high;i++){
        arr1[i] = arr2[i];
    }

}

int main(){

    int arr1[] = {3,5,6,1,2,4,7};
    int size1 = 7;
    int low = 0;
    int high = size1-1;
    int mid = 2;

    traversal(arr1,size1);
    merge(arr1,low,high,mid);
    traversal(arr1,size1);

    return 0;
}

