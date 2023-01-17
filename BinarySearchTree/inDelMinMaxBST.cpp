#include<iostream>
#include<queue>
using namespace std;

class node{
    public:

    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* minimum(node* &root)
{
    node* temp1=root;
    
    while(temp1->left!=NULL){
        temp1=temp1->left;
    }
    return temp1;
}

node* maximum(node*&root)
{
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
void levelOrderTraversal(node * root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node* temp=q.front();
        q.pop();
    if(temp==NULL){
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
    }
    else{
         cout<<temp->data<<" ";
      if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
  
    }
    

}
node* insertIntoBST(node * & root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }

    return root;
}
node* deleteIntoBST(node* &root,int d){
    if(root==NULL){
        return root;
    }
    
    if(root->data==d){

    // zero child
    if(root->left==NULL && root->right==NULL){
        cout<<"node of 0 child to be deleted : "<<root->data <<endl;
        delete root;
        cout<<"node is deleted !!!"<<endl;
        return NULL;
    }

    //one child
    //left child

    if(root->left!=NULL && root->right==NULL){
    cout<<"node of 1 left child to be deleted : "<<root->data <<endl;
        node* temp=root->left;
        delete root;
         cout<<"node is deleted !!!"<<endl;
        return temp;
        
    }

    // right child
     if(root->left==NULL && root->right!=NULL){
    cout<<"node of 1 right child to be deleted : "<<root->data <<endl;
        node* temp=root->right;
        delete root;
         cout<<"node is deleted !!!"<<endl;
        return temp;
        
    }

    // two child
    if(root->left!=NULL && root->right!=NULL){
        int mini=minimum(root->right) -> data;
        cout<<" node to be deleted : "<<root->data<<endl;
        root->data=mini;
        cout<<"now minimum value node to be deleted : "<<root->data<<endl;
       root->right=deleteIntoBST(root->right,mini);
       cout<<"node of value minimum is deleted!!!"<<endl;
       return root;

        }
    }

    else if(root->data>d){
        cout<<"moving to left part of the BST to find lesser value ! "<<root->data<<endl;
        root->left=deleteIntoBST(root->left,d);
        return root;
    }
    else{
        root->right=deleteIntoBST(root->right,d);
        cout<<"moving to right part of the BST to find greater value ! "<<root->data<<endl;
        return root;
    }
}


void takeInput(node* &root){
    int data ;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}

// 10 8 21 7 27 5 4 3 -1
int main(){
node* root=NULL;
cout<<"enter the data to create BST :"<<endl;
takeInput(root);
cout<<"level order traversal : "<<endl;
levelOrderTraversal(root);

cout<<"minimum value node in BST : "<<minimum(root)->data<<endl;
cout<<"maximum value node in BST : "<<maximum(root)->data<<endl;

deleteIntoBST(root,27);
cout<<"level order traversal : "<<endl;
levelOrderTraversal(root);
}
