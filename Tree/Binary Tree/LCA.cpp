#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node(int x)
    {
        data = x;
        left=NULL;
        right=NULL;
    }
};

void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* lca(node* root, int p, int q)
{
    if(root==NULL || root->data==p || root->data==q)
        return root;
    
    node* left = lca(root->left, p, q);
    node* right = lca(root->right, p, q);
    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    else
        return root;
}

int main()
{
   node* root=NULL;
   root = new node(10);
   root->left = new node(20);
   root->right = new node(30);
   root->left->right = new node(35);
   root->left->left = new node(32);
   root->right->left = new node(25);
   root->left->right->right = new node(42);
   inorder(root);
   cout<<"\n";
   node* ans = lca(root,32,42);    
   cout<<ans->data<<" ";
   return 0;
}
