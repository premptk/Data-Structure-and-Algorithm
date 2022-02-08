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

void PrintTree(TreeNode* root)
{
    if(root==NULL)
        return;
    PrintTree(root->left);
    cout<<root->data<<" ";
    PrintTree(root->right);
}

void flatten(TreeNode* root)
{
    TreeNode* cur=root;
    while(cur)
    {
        if(cur->left)
        {
            TreeNode* pre = cur->left;
            while(pre->right)
            {
                pre = pre->right;
            }
            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}

int main()
{
    TreeNode* root=NULL;
    root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    PrintTree(root);
    cout<<"\n";
    flatten(root);
    PrintTree(root);
    return 0;
}
