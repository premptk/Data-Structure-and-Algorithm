#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left,*right;
    TreeNode(int x)
    {
        data = x;
        left=NULL;
        right=NULL;
    }
};

void inorder(TreeNode* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void reorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    
    int sum=0;
    if(root->left)
        sum += root->left->data;
    if(root->right)
        sum += root->right->data;
    if(root->data <= sum)
        root->data = sum;
    else
    {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    
    reorder(root->left);
    reorder(root->right);

    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right)
        root->data = tot;
}

int main()
{
   TreeNode* root=NULL;
   root = new TreeNode(10);
   root->left = new TreeNode(20);
   root->right = new TreeNode(30);
   root->left->right = new TreeNode(35);
   root->left->left = new TreeNode(32);
   root->right->right = new TreeNode(25);
   root->right->left = new TreeNode(5);
   inorder(root);
   cout<<"\n";
   cout<<MaxWidth(root)<<endl;
   reorder(root);
   inorder(root);
   return 0;
}
