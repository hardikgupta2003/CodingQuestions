#include <iostream>
#include<queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTrees(node *root)
{
    cout << "enter the data : " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the  data for inserting in the left of " << data << endl;
    root->left = buildTrees(root->left);

    cout << "enter the  data for inserting in the right of " << data << endl;
    root->right = buildTrees(root->right);
    return root;
}
void Inorder(node* root){
    if(root==NULL){
        return ;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
   
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main()
{

    node *root = NULL;
    root = buildTrees(root);

cout<<"inorder traversal is : ";
   Inorder(root);
   cout<<endl;

cout<<"preorder traversal is : ";
   preorder(root);
   cout<<endl;

   cout<<"postorder traversal is : ";
   postorder(root);
   cout<<endl;
}
