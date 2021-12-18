#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{

    int data;
    struct Node *next;
}node;

void traversal(node *ptr){

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

node * copy (node *ptr,int size){

    node * arrNew[size];

    for(int i = 0;i<size;i++){
        arrNew[i] = (node*)malloc(sizeof(node));
    }

    int i = 0;

    while(ptr!=NULL){
        arrNew[i]->data = ptr->data;
        arrNew[i]->next = ptr->next;
        ptr = ptr->next;
        i++;
    }

    return arrNew[0];
}

int main(){

    node * arr[5];

    for(int i = 0;i<5;i++){
        arr[i] = (node*)malloc(sizeof(node));
    }

    arr[4]->next = NULL;

    int i = 0;
    while(arr[i]!=NULL){
        arr[i]->data = i+1;
        arr[i]->next = arr[i+1];
        i++;
    }

    traversal(arr[0]);
    // node * temp;
    // temp = copy(arr[0],5);
    // traversal(temp);
    
    return 0;
}
