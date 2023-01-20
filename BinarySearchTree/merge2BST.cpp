#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void inorder(TreeNode<int>* root,vector<int>& in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right ,in);
}


TreeNode<int>* bst(int s, int e, vector<int> &in){
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = bst(s, mid-1, in);
    root->right = bst(mid+1, e, in);
    return root;
}
vector<int> merge ( vector<int> &in1, vector<int> &in2){
    vector<int> ans(in1.size() + in2.size());
    int i=0,j=0,k=0;
    while(i<in1.size() && j<in2.size()){
        if(in1[i]<in2[j]){
            ans[k++]=in1[i];
            i++;
        }
        else{
            ans[k++]=in2[j];
            j++;
        }
    }
    while(i<in1.size()){
        ans[k++]=in1[i];
        i++;
    }
    while(j<in2.size()){
        ans[k++]=in2[j];
        j++;
     }
    return ans;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> in1;
    inorder(root1,in1);
    vector<int> in2;
    inorder(root2,in2);
    
    vector<int> merged=merge(in1,in2);
    
    int s=0;
    int e=merged.size()-1;
    
    
    TreeNode<int> * ans=bst(s,e,merged);
    return ans;

    
}
