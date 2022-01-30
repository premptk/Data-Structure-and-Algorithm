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

void verticalTraversal(TreeNode* root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int ver = p.second.first, lvl = p.second.second;
        nodes[ver][lvl].insert(node->data);
        if(node->left) 
            todo.push({node->left, {ver-1,lvl+1}});
        if(node->right)
            todo.push({node->right, {ver+1, lvl+1}});
    }
    vector<vector<int>> ans;
    for(auto it : nodes)
    {
        vector<int> col;
        for(auto p : it.second)
        {
            col.insert(col.end(), p.second.begin(), p.second.end());
        }
        ans.push_back(col);
    }
    for(auto it : ans)
    {
        for(auto p : it)
            cout<<p<<" ";
        cout<<"\n";
    }
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
    verticalTraversal(root);
    return 0;
}
