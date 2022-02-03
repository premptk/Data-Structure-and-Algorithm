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

void inorder(TreeNode* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void make_parent(TreeNode* &root, unordered_map<TreeNode*, TreeNode*> &parent)
{
    queue<TreeNode*> q;
    q.push(root);
    parent[root]=NULL;
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        if(node->left)
        {
            q.push(node->left);
            parent[node->left] = node;
        }

        if(node->right)
        {
            q.push(node->right);
            parent[node->right] = node;
        }
    }
}

int TimeBurn(TreeNode* root, TreeNode* target)
{
    unordered_map<TreeNode*, TreeNode*> parent;
    make_parent(root, parent);
    unordered_map<TreeNode*, bool> visited;
    visited[target]=true;
    queue<TreeNode*> q;
    q.push(target);
    int f1,maxi=0;
    while(!q.empty())
    {
        int size=q.size();
        f1=0;
        for(int i=0;i<size;i++)
        {
            TreeNode* node=q.front();
            q.pop();

            //left
            if(node->left && !visited[node->left])
            {
                q.push(node->left);
                f1=1;
                visited[node->left]=true;
            }

            // right
            if(node->right && !visited[node->right])
            {
                q.push(node->right);
                f1=1;
                visited[node->right]=true;
            }

            //parent
            if(parent[node] && !visited[parent[node]])
            {
                q.push(parent[node]);
                f1=1;
                visited[parent[node]]=true;
            }
        }
        if(f1) maxi++;
    }
    return maxi;
}

int main()
{
   TreeNode* root=NULL;
   root = new TreeNode(10);
   root->left = new TreeNode(20);
   root->right = new TreeNode(30);
   root->left->right = new TreeNode(35);
   root->left->left = new TreeNode(32);
   root->right->right = new TreeNode(25);
   root->right->left = new TreeNode(5);
   inorder(root);
   cout<<"\n";
   cout<<TimeBurn(root, root->left);
   return 0;
}
