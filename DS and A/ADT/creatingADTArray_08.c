#include<stdio.h> 
#include<stdlib.h>

typedef struct myArray{

    int total_size;
    int used_size;
    int *ptr1;

}arr;

void buildArray(arr *ptr,int tsize,int usize){

    ptr->total_size = tsize;
    ptr->used_size = usize;
    ptr->ptr1 = (int*)malloc(usize*sizeof(int));

}

void setVal(arr *ptr){

    for(int i =0;i<ptr->used_size;i++){

        int temp;
        printf("Enter the %dth element of the array\n",i+1);
        scanf("%d",&temp);
        ptr->ptr1[i] = temp;
    }
}

void show(arr *ptr){

    for(int i =0;i<ptr->used_size;i++){
        printf("The %dth element of the array is %d\n",i+1,ptr->ptr1[i]);

    }

}

int main(){
    
    int tsize,usize;
    printf("Enter the total size\n");
    scanf("%d",&tsize);
    printf("Enter the used size\n");
    scanf("%d",&usize);    
    arr array;
    arr *ptr = &array;

    buildArray(ptr,tsize,usize);
    setVal(ptr);
    show(ptr);

    return 0;
}
