#include<stdio.h>

int linearSearch(int *ptr,int size,int elem){

    for(int i = 0;i<size;i++){
        if(elem==*(ptr+i)){
            return i;
        }
    }

    return -1;
}

int main(){
    
    int arr[] = {1,2,3,4,5,6};
    int *ptr = arr;
    int size = 6;
    int elem;

    printf("Enter the element of the array\n");
    scanf("%d",&elem);

    int result;
    result = linearSearch(ptr,size,elem);

    printf("The index of the element in the array is %d\n",result);

    return 0;
}
