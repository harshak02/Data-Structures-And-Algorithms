#include<iostream>
using namespace std;

void tp(int *ptr){
    (*ptr)++;
}

int main(){

    int a = 6;
    int *ptr = &a;
    cout<<a<<endl;
    tp(ptr);
    cout<<a<<endl;
    
    return 0;
}
