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

void Morris(TreeNode* root, vector<int> &in)
{
    TreeNode* cur = root;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            in.push_back(cur->data);
            // pre.push_back(cur->data)
            cur = cur->right;
        }
        else
        {
            TreeNode* prev=cur->left;
            while(prev->right!=NULL && prev->right!=cur)
            {
                prev = prev->right;
            }
            if(prev->right==NULL)
            {   
                prev->right = cur;
                // pre.push_back(cur->data)
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                in.push_back(cur->data);
                cur=cur->right;
            }
        }
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
    vector<int> in;
    Morris(root, in);
    for(auto it: in)
        cout<<it<<" ";
    return 0;
}
