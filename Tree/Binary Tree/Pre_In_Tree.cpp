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


void preorder(TreeNode* root, vector<int> &pre)
{
    if(root==NULL)
        return;
    pre.push_back(root->data);
    inorder(root->left, pre);
    inorder(root->right, pre);
}

TreeNode* BuiltTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
{
    if(preStart > preEnd || inStart > inEnd) 
        return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inroot = mp[root->data];
    int numsLeft = inroot - inStart;

    root->left = BuiltTree(preorder, preStart+1, preStart + numsLeft,
                            inorder, inStart, inroot-1, mp);

    root->right = BuiltTree(preorder, preStart+numsLeft+1, preEnd,
                            inorder, inroot+1, inEnd, mp);

    return root;
}

TreeNode* Construct(vector<int> &inorder, vector<int> &preorder)
{
    map<int,int> mp;
    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;
    
    TreeNode* root = BuiltTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
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
    vector<int> pre;
    preorder(root, pre);
    TreeNode* temp = Construct(in, pre);
    PrintTree(temp);
    return 0;
}
