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
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main()
{

    node *root = NULL;
    root = buildTrees(root);

    cout<<"printing the level order traversal output : "<<endl;
    levelOrderTraversal(root);
}
