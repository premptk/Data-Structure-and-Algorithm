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

TreeNode* buildBST(vector<int> &pre, int& i, int bound)
{
    if(i==pre.size() || pre[i]>bound)
        return NULL;
    TreeNode* root = new TreeNode(pre[i++]);
    root->left = buildBST(pre,i,root->data);
    root->right = buildBST(pre,i,bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int> &pre)
{
    int i=0;
    return buildBST(pre, i, INT_MAX);
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
    vector<int> pre = {10, 5,3,7,6,15,20,30};
    TreeNode* temp = bstFromPreorder(pre);
    PrintTree(root);
    return 0;
}
