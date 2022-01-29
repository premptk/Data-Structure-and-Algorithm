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


bool isLeaf(TreeNode* root)
{
    if(root->left==NULL && root->right==NULL)
        return true;
    return false;
}

void addLeft(TreeNode* root, vector<int> &res)
{
    TreeNode* node=root->left;
    while(node!=NULL)
    {
        if(!isLeaf(node))
            res.push_back(node->data);
        if(node->left)
            node = node->left;
        else node = node->right;
    }
}

void addLeaf(TreeNode* node, vector<int> &res)
{
    if(node!=NULL)
    {
        if(isLeaf(node)) res.push_back(node->data);
        addLeaf(node->left,res);
        addLeaf(node->right,res);
    }
}

void addRight(TreeNode* root, vector<int> &res) 
{
    TreeNode* cur = root->right;
    vector<int> tmp;
    while (cur) {
        if (!isLeaf(cur)) tmp.push_back(cur->data);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for (int i = tmp.size()-1; i >= 0; --i) {
        res.push_back(tmp[i]);
    }
}

void boundary(TreeNode* root)
{
    vector<int> res;
    if(!isLeaf(root)) res.push_back(root->data); 
    addLeft(root,res);
    addLeaf(root,res);
    addRight(root,res);
    for(auto it: res)
        cout<<it<<" ";
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
    boundary(root);
    return 0;
}
