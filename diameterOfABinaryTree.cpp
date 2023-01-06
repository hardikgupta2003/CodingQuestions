/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    int solve(Node* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);
        ans=max(ans,l+r+1);
        return 1+max(l,r);
    }
    
    int diameter(Node* root) {
        // Your code here
        int ans=0;
        solve(root,ans);
        return ans;
    }
};

