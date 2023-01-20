#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inordr(TreeNode<int>* root,vector<int>& inodr){
        if(root==NULL){
            return ;
        }
        inordr(root->left,inodr);
        inodr.push_back(root->data);
        inordr(root->right,inodr);
    }

TreeNode<int>* flatten(TreeNode<int>* root)
{
     vector<int> inodr;
    inordr(root,inodr);
    int i=0;
    int size=inodr.size();
    
    TreeNode<int>* newRoot=new TreeNode<int>(inodr[0]);
    TreeNode<int>* curr=newRoot;
    
    for(int i=1;i<size;i++){
       TreeNode<int>* temp=new TreeNode<int>(inodr[i]);
        temp->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;
    
    return newRoot;
}
