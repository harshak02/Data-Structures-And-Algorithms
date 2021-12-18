#include<iostream>
using namespace std;

void traversal(int arr[],int size){

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void countSort(int arr[],int size){

    int grt = 0;
    
    for(int i = 0;i<size;i++){
        if(grt<arr[i]){
            grt = arr[i];
        }
    }

    // int countArray[grt];
    int *countArray;
    countArray = (int*)malloc(grt*sizeof(int));

    for(int i = 0;i<grt;i++){
        countArray[i] = 0;
    }

    for(int j = 0;j<grt;j++){
        for(int i = 0;i<size;i++){
            if(arr[i]==j+1){
                countArray[j]+=1;
            }
        }
    }

    int k = 0;

    for(int i = 0;i<grt;i++){
        if(countArray[i]>0){
            while(countArray[i]!=0){
                arr[k] = i+1;
                k++;
                countArray[i]--;
            }
        }
    }

}

int main(){

    // int arr[] = {9,1,4,2,3,5,7,8,6};
    // int size = 9;
    int arr[] = {9,1,4,14,4,15,6};
    int size = 7;



    traversal(arr,size);
    countSort(arr,size);
    traversal(arr,size);
    
    return 0;
}
