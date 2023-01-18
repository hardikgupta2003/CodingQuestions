#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
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
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int> * temp=root;
    int succ=-1;
    int pred=-1;
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
           
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }
        
        //pred
        BinaryTreeNode<int> * leftTree=temp->left;
        while(leftTree!=NULL){
            pred=leftTree->data;
            leftTree=leftTree->right;
        }
        
        BinaryTreeNode<int> * rightTree=temp->right;
        while(rightTree!=NULL){
            succ=rightTree->data;
            rightTree=rightTree->left;
        }
       
//         pair<int,int> ans=make_pair(pred,succ); 
//          return ans;
    return {pred,succ};
    
    
       
}
