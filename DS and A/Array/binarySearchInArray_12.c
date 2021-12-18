#include<stdio.h> 
//Used only for the sorted arrays

int binarySearch(int arr[],int elem,int size){

    int low = 0;
    int high = size-1;

    while(low<=high){

        int mid = (int)(low+high)/2;
        if(arr[mid] == elem){
            return mid;
        }

        else if (arr[mid]> elem){
            high = mid -1;
        }

        else{
            low = mid + 1;
        }
    }

    return -1;

}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int *ptr = arr;
    int size;
    size = sizeof(arr)/sizeof(int);// for this the array should not be declared as arr[100];
    int elem;

    printf("enter the element of the array\n");
    scanf("%d",&elem);
    int res;
    res = binarySearch(arr,elem,size);

    printf("The index of the element in the array is %d\n",res);

    return 0;
}
