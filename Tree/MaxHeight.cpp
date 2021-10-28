#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left,*right;
    node(int x)
    {
        key = x;
        left=NULL;
        right=NULL;
    }
};

void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void inorderIterative(node* root)
{
    stack<node*> s;
    node* curr = root;
    while(s.empty()==false || curr!=NULL)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr = curr->right;
    }
}

void preorderIterative(node* root)   // Check
{
    if(root==NULL)  return;
    stack<node*> s;
    s.push(root);
    node* curr;
    while(s.empty()==false)
    {
        curr = s.top();
        cout<<curr->key<<" ";
        s.pop();
        if(curr->right!=NULL) s.push(curr->right);
        if(curr->left!=NULL) s.push(curr->left);    
        curr = s.top(); s.pop();
        cout<<curr->key<<" ";
    }
}

bool searchRecursive(node* root, int x)
{
    if(root==NULL)
        return false;
    else if(root->key==x)
        return true;
    else if(root->key > x)
        return searchRecursive(root->left, x);
    else 
        return searchRecursive(root->right, x);
}

bool searchIterative(node* root, int x)
{
    while(root!=NULL)
    {
        if(root->key == x)
            return true;
        else if(root->key > x)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

node* insert(node* root, int x)
{
    if(root==NULL)
        return new node(x);
    else if(root->key > x)
        root->left = insert(root->left, x);
    else if(root->key < x)
        root->right = insert(root->right, x);
    return root;
}

int heightNode(node* root)
{
   if(root==NULL)
      return 0;
   return max(heightNode(root->left), heightNode(root->right))+1;
}

void height(node* root)
{
   int lh = heightNode(root->left);
   int rh = heightNode(root->right);
   cout<<lh<<" "<<rh;
}

int main()
{
   node* root=NULL;
   root = insert(root, 40);
   root = insert(root, 20);
   root = insert(root, 30);
   root = insert(root,5);
   root = insert(root,45);
   root = insert(root, 50);
   root = insert(root, 2);
   inorder(root);
   cout<<"\n";
   height(root);
   return 0;
}
