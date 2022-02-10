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

TreeNode* insert(TreeNode* root, int x)
{
    if(root==NULL)
    {
        return new TreeNode(x);
    }
    else if(root->data > x)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

void PrintTree(TreeNode* root)
{
    if(root==NULL)
        return;
    PrintTree(root->left);
    cout<<root->data<<" ";
    PrintTree(root->right);
}

TreeNode* LastNode(TreeNode* root)
{
    if(root->right!=NULL)
        root = root->right;
    return root;
}

TreeNode* helper(TreeNode* root)
{
    if(root->left==NULL)
        return root->right;
    else if(root->right==NULL)
        return root->left;
    TreeNode* rightNode = root->right;
    TreeNode* lastNode = LastNode(root->left);
    lastNode->right = rightNode;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key)
{
    if(root==NULL)
        return NULL;
    TreeNode* dummy = root;
    if(root->data == key)
        return helper(root);
    while(root!=NULL)
    {
        if(root->data > key)  //left
        {
            if(root->left!=NULL && root->left->data == key)
            {
                root->left =  helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if(root->right!=NULL && root->right->data==key)
            {
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
}

int main()
{
    TreeNode* root=NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 6);
    PrintTree(root);
    cout<<"\n";
    root = deleteNode(root, 7);
    PrintTree(root);
    return 0;
}
