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

tree * create_node(int val){

    tree *temp;
    temp = new tree (val);

    return temp;

}

void levelOrder(tree *ptr){

    if(ptr==NULL){
        exit(0);
    }

    queue <tree *> q;
    tree * temp = ptr;
    q.push(temp);
    int height = 0;

    while(q.size()>0){

        tree * temp2;
        temp2 = q.front();
        cout<<temp2->data<<" ";
        q.pop();

        if(temp2->left!=NULL){
            q.push(temp2->left);

        }
        
        if(temp2->right!=NULL){
            q.push(temp2->right); 
        
        }
        
    }

}

void inOrder(tree * root){

    if(root->left!=NULL){
        inOrder(root->left);
    }

    cout<<root->data<<" ";

    if(root->right!=NULL){
        inOrder(root->right);
    }

}

void preOrder(tree * root){

    cout<<root->data<<" ";

    if(root->left!=NULL){
        preOrder(root->left);
    }

    if(root->right!=NULL){
        preOrder(root->right);
    }

}

void postOrder(tree * root){

    if(root->left!=NULL){
        postOrder(root->left);
    }

    if(root->right!=NULL){
        postOrder(root->right);
    }

    cout<<root->data<<" ";

}

int isBst(tree * root,int min,int max){

    if(root == NULL){
        return 1;
    }

    if(root->data < min || root->data > max){
        return 0;
    }

    if(!isBst(root->left,min,root->data)){
        return 0;
    }

    if(!isBst(root->right,root->data,max)){
        return 0;
    }

    return 1;
}

tree * binarySearch(tree * root,int key){
    tree * temp = root;

    if(temp == NULL){
        return temp;
    }

    if(key == temp->data){
        return temp;
    }

    else if(key > temp->data && temp->right!=NULL){
        return temp->right;
    }

    else if(key < temp->data && temp->left!=NULL){
        return temp->left;
    }
    
    else{
        return NULL;
    }

}

tree * binarySearchIter(tree * root,int key){

    tree * temp = root;
    tree * ret = NULL;

    while(1){

        if(key == temp->data){
            ret = temp;
            break;
        }

        else if(key > temp->data && temp->right!=NULL){
            temp = temp->right;
        }

        else if(key < temp->data && temp->left!=NULL){
            temp = temp->left;
        }

        else{
            break;
        }
    }

    return ret;
}

int main(){

	tree * root;
	root = create_node(5);
	tree * fir;
	fir = create_node(3);
	tree * sec;
	sec = create_node(7);
	tree * thi;
	thi = create_node(2);
	tree * fou;
	fou = create_node(4);
	tree * fiv;
	fiv = create_node(6);
	tree * six;
	six = create_node(8);
	tree * sev;
	sev = create_node(1);
	tree * eig;
	eig = create_node(9);
	
	root->left = fir;
	root->right = sec;
	fir->left = thi;
	fir->right = fou;
	sec->left = fiv;
	sec->right = six;
	thi->left = sev;
	six->right = eig;

    int min = 0;
    int max = 100;

    if(isBst(root,min,max)){
        cout<<"The given tree is binary search tree"<<endl;
    }

    else{
        cout<<"The given tree is not binary search tree"<<endl;
    }

    cout<<"Inorder"<<endl;
    inOrder(root);
    cout<<endl;

    cout<<"preorder"<<endl;
    preOrder(root);
    cout<<endl;

    cout<<"postorder"<<endl;
    postOrder(root);
    cout<<endl;

    cout<<"Levelorder"<<endl;
    levelOrder(root);
    cout<<endl;

    int key = 2;
    tree * nodeImp;
    nodeImp = binarySearch(root,key);

    cout<<(nodeImp->left)->data<<endl;
    if(nodeImp->right!=NULL){
    cout<<(nodeImp->right)->data<<endl;
    }

    return 0;
}
