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

bool getPath(TreeNode* root, vector<int> &arr, int x)
{
    if(root==NULL)
        return false;
    arr.push_back(root->data);
    if(root->data == x)
    {
        return true;
    }
    if(getPath(root->left,arr,x) || getPath(root->right,arr,x))
        return true;
    arr.pop_back();
    return false;
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
    vector<int> ans;
    getPath(root, ans, 45);
    for(auto it : ans)
        cout<<it<<" ";
    return 0;
}
