#include <bits/stdc++.h> 
/*
Node structure which is used.

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~Node()
	{
		if (left != NULL)
		{
			delete left;
		}
		if (right != NULL)
		{
			delete right;
		}
	}

};

*/
void solve(Node* root,vector<int> &ans){
    if(root==NULL){
        return ;
    }
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}
int KthLargest(Node* root, int k)
{
	vector<int> ans;
    
    solve(root,ans);
    int size=ans.size();
    if(k>size){
        return -1;
    }
    return ans[size-k];
}
