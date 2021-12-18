#include<iostream>
#include<vector>
#include<map>
#include <queue>
using namespace std;

class tree{

    public :
    int data;
    tree *left;
    tree *right;

    tree(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

tree * build(vector <int> preOrder,vector <int> inOrder,int preStart,int preEnd,int inPos,int inEnd,map<int,int> inMap){

    if(preStart>preEnd || inPos>inEnd){
        return NULL;
    }

    else{
        int key;
        key = preOrder[preStart];
        tree * ins_tree;
        ins_tree = new tree(key);
        int root_pos;
        root_pos = inMap[ins_tree->data];
        int numsLeft = root_pos - inPos;

        ins_tree->left = build(preOrder,inOrder,preStart +1 ,preStart+numsLeft,inPos,root_pos-1,inMap);
        ins_tree->right = build(preOrder,inOrder,preStart + root_pos+1 ,preEnd,root_pos+1,inEnd,inMap);

        return ins_tree;
    }
}


tree * treeBuild(vector <int> preOrder,vector <int> inOrder){

    map <int,int> inMap;
    
    for(int i = 0;i<inOrder.size();i++){
        inMap[inOrder[i]] = i;
    }

    tree * root;
    root = build(preOrder,inOrder,0,preOrder.size()-1,0,inOrder.size()-1,inMap);

    return root;
}

void levelOrder(tree *ptr){

    if(ptr==NULL){
        exit(0);
    }

    queue <tree *> q;
    tree * temp = ptr;
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
                cout<<temp2->data<<" ";
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
    }

}

int main(){

    vector <int> vec1 = {10,20,40,50,30,60};
    vector <int> vec2 = {40,20,50,10,60,30};

    tree * root;
    root = treeBuild(vec1,vec2);

    levelOrder(root);
    cout<<endl;
    
    return 0;
}
