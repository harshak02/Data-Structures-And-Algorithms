#include<iostream>
#include<vector>

using namespace std;

class myArray{

    private :
    int t_size;
    int u_size;
    int *ptr;

    public :
    myArray(){
        
        cout<<"Enter the total size "<<endl;
        cin>>t_size;
        cout<<"Enter the used size "<<endl;
        cin>>u_size;
        ptr = (int*)malloc(t_size*sizeof(int));

    }

    void setVal();
    void show();

};

void myArray :: setVal(){

    for(int i =0;i<u_size;i++){

        int temp;
        cout<<"Enter the "<<i+1<<" th element"<<endl;
        cin>>temp;
        ptr[i] = temp;
    }
}

void myArray :: show(){

    for(int i =0;i<u_size;i++){
        cout<<"The "<<i+1<<" th element is "<<ptr[i]<<endl;
    }
}

int main(){
    
    myArray arr;
    arr.setVal();
    arr.show();

    return 0;
}
