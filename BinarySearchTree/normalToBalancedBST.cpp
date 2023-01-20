void solve(TreeNode<int>* root, vector<int> &in){
    if(root == NULL)
        return ;
    
    solve(root->left, in);
    in.push_back(root->data);
    solve(root->right, in);
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

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorder;
    solve(root, inorder);
    
    return bst(0, inorder.size()-1, inorder);
}
