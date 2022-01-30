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

void topView(TreeNode* root)
{
    if(root==NULL)
        return;
    queue<pair<TreeNode*,int>> q;
    map<int,int> mp;
    q.push({root, 0});
    while(!q.empty())
    {
        auto p = q.front();
        auto node = p.first;
        int line=p.second;
        q.pop();
        if(mp.find(line) == mp.end())
            mp[line]=node->data;
        if(node->left!=NULL)
            q.push({node->left, line-1});
        if(node->right!=NULL)
            q.push({node->right, line+1});
    }

    vector<int> ans;
    for(auto it:mp)
        ans.push_back(it.second);
        
    for(auto it:ans)
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
    topView(root);
    return 0;
}
