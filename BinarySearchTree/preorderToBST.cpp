#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
BinaryTreeNode<int>* createBST(vector<int> &preorder,int mini, int maxi,int &index,int n){
    if(index>=n)
        return NULL;
    
    if(preorder[index]>maxi || preorder[index]<mini)
        return NULL;
    
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(preorder[index]);
    index++;
    root->left=createBST(preorder,mini,root->data,index,n);
    root->right=createBST(preorder,root->data,maxi,index,n);
    return root;
    
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int n=preorder.size();
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int index=0;
    BinaryTreeNode<int>* ans= createBST(preorder,mini,maxi,index,n);
    return ans;
}
