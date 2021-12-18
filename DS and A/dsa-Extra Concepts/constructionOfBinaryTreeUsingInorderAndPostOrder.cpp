#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

tree * build(vector <int> postOrder,vector <int> inOrder,int postStart,int postEnd,int inPos,int inEnd,map<int,int> inMap){

    if(postStart>postEnd || inPos>inEnd){
        return NULL;
    }

    else{
        int key;
        key = postOrder[postEnd];
        tree * ins_tree;
        ins_tree = new tree(key);
        int root_pos;
        root_pos = inMap[ins_tree->data];

        ins_tree->left = build(postOrder,inOrder,postStart,postStart+root_pos-inPos-1,inPos,root_pos-1,inMap);
        ins_tree->right = build(postOrder,inOrder,postStart + root_pos-inPos ,postEnd-1,root_pos+1,inEnd,inMap);

        return ins_tree;
    }
}


tree * treeBuild(vector <int> postOrder,vector <int> inOrder){

    map <int,int> inMap;
    
    for(int i = 0;i<inOrder.size();i++){
        inMap[inOrder[i]] = i;
    }

    tree * root;
    root = build(postOrder,inOrder,0,postOrder.size()-1,0,inOrder.size()-1,inMap);

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

    vector <int> vec1 = {40,50,20,60,30,10};
    vector <int> vec2 = {40,20,50,10,60,30};

    tree * root;
    root = treeBuild(vec1,vec2);

    levelOrder(root);
    cout<<endl;
    
    return 0;
}
