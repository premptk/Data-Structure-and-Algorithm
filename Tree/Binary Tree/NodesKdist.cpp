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

void make_parent(unordered_map<TreeNode*, TreeNode*> &parent, TreeNode* &root)
{
    queue<TreeNode*> q;
    q.push(root);
    parent[root]=NULL;
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if(node->left)
        {
            parent[node->left] = node;
            q.push(node->left);
        }
        if(node->right)
        {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<int> NodesK(TreeNode* root, TreeNode*  target, int k)
{
    unordered_map<TreeNode*, TreeNode*> parent;
    make_parent(parent, root);
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int cur_size=0;
    while(!q.empty())
    {
        int size=q.size();
        if(cur_size==k) 
            break;
        cur_size++;
        for(int i=0;i<size;i++)
        {
            TreeNode* node = q.front();
            q.pop();

            //left
            if(node->left!=NULL && !visited[node->left]){
                q.push(node->left);
                visited[node->left] = true;
            }

            //right
            if(node->right!=NULL && !visited[node->right]){
                q.push(node->right);
                visited[node->right] = true;
            }

            //parent
            if(parent[node]!=NULL && !visited[parent[node]]){
                q.push(parent[node]);
                visited[parent[node]] = true;
            }
        }
    }
    
    vector<int> res;
    while(!q.empty())
    {
        res.push_back(q.front()->data);
        q.pop();
    }
    return res;
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
   vector<int> ans;
   ans = NodesK(root, root->left, 1);
   for(auto it:ans)
    cout<<it<<" ";
   return 0;
}
