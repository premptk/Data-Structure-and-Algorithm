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

void rightView(TreeNode* root,int level, vector<int> &ans)
{
    if(root==NULL)
        return;
    if(level==ans.size())
        ans.push_back(root->data);
    rightView(root->right,level+1,ans);
    rightView(root->left,level+1,ans);
}


void leftView(TreeNode* root, int level, vector<int> &ans)
{
    if(root==NULL)
        return;
    if(level==ans.size())
        ans.push_back(root->data);
    leftView(root->left,level+1,ans);
    leftView(root->right,level+1,ans);
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
    rightView(root,0,ans);
    for(auto it : ans)
        cout<<it<<" ";
    ans.clear();
    cout<<"\n";
    leftView(root,0,ans);
    for(auto it : ans)
        cout<<it<<" ";
    return 0;
}
