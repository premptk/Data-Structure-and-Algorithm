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

void ZigZag(TreeNode* root)
{
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    bool dir=true;
    while(!q.empty())
    {
        int size=q.size();
        vector<int> row(size);
        for(int i=0;i<size;i++)
        {
            auto node = q.front();
            q.pop();
            int index = (dir) ? i : (size-1-i);
            row[index] = node->data;
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
        }
        result.push_back(row);
        dir = !dir;
    }
    for(auto it: result)
    {
        for(auto z:it)
            cout<<z<<" ";
        cout<<endl;
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
    ZigZag(root);
    return 0;
}
