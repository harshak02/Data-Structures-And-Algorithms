#include<iostream>
using namespace std;

void traversal(int arr[],int size){

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void merge(int arr[],int low,int mid,int high){

    int i = low;
    int j = mid+1;
    int k = low;
    int temp[100];

    while(i<=mid && j<=high){

        if(arr[i]>=arr[j]){
            temp[k] = arr[j];
            j++;
        }

        else{
            temp[k] = arr[i];
            i++;
        }

        k++;
    }

    if(i<=mid){
        while(i<=mid){
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    else{
        while(j<=high){
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    for(int i = 0;i<=high;i++){
        arr[i] = temp[i];
    }

}

void mergeSort(int arr[],int low,int high){

    if(low<high){

        int mid = (int) ((low+high)/2);
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);

    }
}

int main(){

    int arr[] = {6,5,9,4,1,7,8,2,3};
    int size = 9;
    int low = 0;
    int high = 8;//-->indices

    traversal(arr,size);
    mergeSort(arr,low,high);
    traversal(arr,size);

    
    return 0;
}
