#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left, *right;
    TreeNode(int x)
    {
        data=x;
        left=right=NULL;
    }
};

bool checkSymmetric(TreeNode* Left, TreeNode* Right)
{
    if(Left==NULL || Right==NULL)
        return Left==Right;
    if(Left->data != Right->data)
        return false;
    return checkSymmetric(Left->left,Right->right) && checkSymmetric(Left->right, Right->left);
}

bool isSymmetric(TreeNode* root)
{
    return root==NULL || checkSymmetric(root->left,root->right);
}


int main()
{
    TreeNode* root=NULL;
    root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(35);
    root->left->right = new TreeNode(40);
    root->left->right->left = new TreeNode(45);
    root->left->right->right = new TreeNode(50);
    root->left->right->right->right = new TreeNode(60);
    cout<<isSymmetric(root);
    return 0;
}
