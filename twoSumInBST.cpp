#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
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
    
};
***************/
void inordr(BinaryTreeNode<int>* root,vector<int> &inodr){
    if(root==NULL){
    return ;
    }
    inordr(root->left,inodr);
    inodr.push_back(root->data);
    inordr(root->right,inodr);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> inodr;
    inordr(root,inodr);
    int i=0;
    int j=inodr.size()-1;
    
    while(i<j){
        if(inodr[i]+inodr[j]==target){
            return true;
        }
        else if(inodr[i]+inodr[j]>target){
            j--;
        }
        else{
            i++;
        }
    
    }
        
    return false;
 
}
