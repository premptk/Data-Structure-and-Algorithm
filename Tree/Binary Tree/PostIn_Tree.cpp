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

void inorder(TreeNode* root, vector<int> &in)
{
    if(root==NULL)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}


void postorder(TreeNode* root, vector<int> &post)
{
    if(root==NULL)
        return;
    postorder(root->left, post);
    postorder(root->right, post);
    post.push_back(root->data);
}

TreeNode* BuiltTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
{
    if(postStart > postEnd || inStart > inEnd)
        return NULL;
    
    TreeNode* root = new TreeNode(postorder[postEnd]);
    int inroot = mp[root->data];
    int range = inroot - inStart;
    root -> left = BuiltTree(postorder, postStart, postStart + range - 1, inorder, inStart, inroot - 1, mp);
    root -> right = BuiltTree(postorder, postStart + range, postEnd-1, inorder, inroot+1, inEnd, mp);
    return root;
}

TreeNode* Construct(vector<int> &inorder, vector<int> &postorder)
{
    map<int,int> mp;
    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;
    
    TreeNode* root = BuiltTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
    return root;
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
    vector<int> in;
    inorder(root, in);
    vector<int> post;
    postorder(root, post);
    TreeNode* temp = Construct(in, post);
    PrintTree(temp);
    return 0;
}
