#include<stdio.h>

void show(int arr[100],int size){

for(int i = 0;i<size;i++){

printf("%d ",arr[i]);

}
printf("\n");
}

int insert(int arr[100],int size,int index){

if(index>100){

return -1;
}

else{

for(int i = index;i<size-1;i++){

arr[i] = arr[i+1];

}

return 1;


}
}

int main()
{
    int arr[100] = {1,2,3,4,5};
    int size;
    size = 5;
    show (arr,size);
    int res;
    res = insert(arr,size,2);
    res = 1 ? printf("The deletion is possible\n") : printf("The deletion is not possible\n");
    size--;
    show(arr,size);
    return 0;
}