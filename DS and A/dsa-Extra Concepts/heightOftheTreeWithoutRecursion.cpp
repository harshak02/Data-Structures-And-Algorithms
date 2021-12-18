#include<iostream>
#include<queue>
using namespace std;

class tree{

    public :
    int data;
    tree * left;
    tree * right;

    tree(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};

tree * new_node(int val){

    tree *temp;
    temp = new tree (val);

    return temp;

}

void preOrder(tree *ptr){

    int temp;

    if(ptr == NULL){
        temp = -1;
    }

    else{
        cout<<ptr->data<<" ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }

}

void inOrder(tree *ptr){

    int temp;

    if(ptr == NULL){
        temp = -1;
    }

    else{
        inOrder(ptr->left);
        cout<<ptr->data<<" ";
        inOrder(ptr->right);
    }
}

void postOrder(tree *ptr){

    int temp;

    if(ptr == NULL){
        temp = -1;
    }

    else{
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout<<ptr->data<<" ";
    }

}

int maxi(int a,int b){

    if(a>=b){
        return a;
    }

    else{
        return b;
    }
}

int get_height(tree *ptr){

    if(ptr==NULL){
        return -1;
    }

    queue <tree *> q;
    tree * temp = ptr;
    int height = 0;
    q.push(temp);

    while(1){

        int size = q.size();

        if(size==0){
            break;
        }

        else{

            while(size>0){
                tree * temp2;
                temp2 = q.front();
                q.pop();

                if(temp2->left!=NULL){
                    q.push(temp2->left);
                }

                if(temp2->right!=NULL){
                    q.push(temp2->right); 
                }

                size--;
            }
        
        }
        height++;
    }

    return height;
}

int main(){

    tree *root;
    root = new_node(10);
    tree *t2;
    t2 = new_node(20);
    tree *t3;
    t3 = new_node(30);
    tree *t4;
    t4 = new_node(40);
    tree *t5;
    t5 = new_node(50);
    tree *t6;
    t6 = new_node(60);
    tree *t7;
    t7 = new_node(70);
    tree *t8;
    t8 = new_node(80);
    tree *t9;
    t9 = new_node(90);
    tree *t10;
    t10 = new_node(100);

    root->left = t2;
    root->right = t3;

    t2->left  = t4;
    t2->right = t5;

    t3->right = t6;
    t5->left = t7;
    t5->right = t8;

    t6->right = t9;
    t7->left = t10;

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;

    cout<<"The height of the binary tree is "<<get_height(root)<<endl;

    return 0;
}
