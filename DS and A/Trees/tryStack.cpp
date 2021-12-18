#include<iostream>
#include<stack>
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

void preOrderIter(tree *ptr){

    stack <tree*> treeStack;
    treeStack.push(ptr);

    if(ptr==NULL){
        exit(0);
    }

    while(1){

        if(treeStack.empty()){
            break;
        }

        else{
            tree * curr = treeStack.top();
            cout<<curr->data<<" ";
            treeStack.pop();

            if(curr->right!=NULL){
               treeStack.push(curr->right); 
            }

            if(curr->left!=NULL){
                treeStack.push(curr->left);  
            }
        }
    }
}

void inOrderIter(tree *ptr){

    stack <tree*> treeStack;
    tree * curr = ptr;

    if(ptr==NULL){
        exit(0);
    }

    while(curr != NULL || !treeStack.empty()){//why we are using here is first stack is empty so it runs by curr!=NULL and ends with curr == NULL

        while(curr!=NULL){
            treeStack.push(curr);
            curr = curr->left;
        }

        curr = treeStack.top();
        treeStack.pop();
        cout<<curr->data<<" ";

        curr = curr->right;

    }
}

void postOrderIter(tree *ptr){

    stack <tree*> stack1;
    stack <tree*> stack2;

    stack1.push(ptr);
    tree * curr;

    while(!stack1.empty()){
        curr = stack1.top();
        stack1.pop();
        stack2.push(curr);

        if(curr->left!=NULL){
            stack1.push(curr->left);
        }

        if(curr->right!=NULL){
            stack1.push(curr->right);
        }

    }

    while(!stack2.empty()){
        
        curr = stack2.top();
        cout<<curr->data<<" ";
        stack2.pop();

    }

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

    int temp;
    if(ptr == NULL){
        temp = -1;
    }

    else{
        int l,r;
        l = get_height(ptr->left);
        r = get_height(ptr->right);

        temp = maxi(l,r) + 1;
    }

    return temp;
}

int get_height_nonrec(tree *ptr){

    int temp;
    if(ptr == NULL){
        temp = -1;
    }

    else{
        int l,r;
        l = get_height(ptr->left);
        r = get_height(ptr->right);

        temp = maxi(l,r) + 1;
    }

    return temp;
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

    preOrderIter(root);
    cout<<endl;

    inOrderIter(root);
    cout<<endl; 

    postOrderIter(root);
    cout<<endl; 

    cout<<"The height of the binary tree is "<<get_height(root)<<endl;

    return 0;
}
