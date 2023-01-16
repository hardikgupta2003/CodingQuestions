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
// 10 8 21 7 27 5 4 3 -1
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
void takeInput(node*&root){
    int data ;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}
int main(){
node* root=NULL;
cout<<"enter the data to create BST :"<<endl;
takeInput(root);
cout<<"level order traversal : "<<endl;
levelOrderTraversal(root);
}
