// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

typedef struct Node{
    
    int data;
    struct Node *next;
    
}node;

node * deleteStart(node * head){
    node * p = head;
    int val = p->data;
    cout<<"The deleted value is "<<val<<endl;
    node * q = head->next;
    free(head);
    
    return q;
};

void traversal(node * head){
    
    node * ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    
    printf("\n");
}

int main() {
    
    node *head;
    head = (node*)malloc(sizeof(node));

    node *second;
    second = (node*)malloc(sizeof(node));

    node *third;
    third = (node*)malloc(sizeof(node));

    node *fourth;
    fourth = (node*)malloc(sizeof(node));

    node *fifth;
    fifth = (node*)malloc(sizeof(node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    traversal(head);
    head = deleteStart(head);
    traversal(head);


    return 0;
}
