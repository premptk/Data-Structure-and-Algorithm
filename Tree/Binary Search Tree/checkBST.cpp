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

bool isValid(TreeNode* root, int minval, int maxval)
{
    if(root == NULL)
        return true;
    if(root->data > maxval || root->data < minval)
        return false;
    return isValid(root->left, minval, root->data) && isValid(root->right, root->data, maxval);
}

bool checkBST(TreeNode* root)
{
    return isValid(root, INT_MIN, INT_MAX);
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
    cout<<checkBST(root)<<endl;
    return 0;
}
