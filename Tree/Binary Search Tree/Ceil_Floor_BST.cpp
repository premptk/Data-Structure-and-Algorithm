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

TreeNode* insert(TreeNode* root, int x)
{
    if(root==NULL)
    {
        return new TreeNode(x);
    }
    else if(root->data > x)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

int findCeil(TreeNode* root, int key)
{
    int ceil = -1;
    while(root)
    {
        if(root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        if(key > root->data){
            root=root->right;
        }
        else
        {
            ceil = root->data;
            root=root->left;
        }
    }
    return ceil;
}

int findFloor(TreeNode* root, int key)
{
    int ceil = -1;
    while(root)
    {
        if(root->data==key){
            ceil = root->data;
            return ceil;
        }
        else if(root->data < key){
            ceil = root->data;
            root = root->right;
        }
        else
            root=root->left;
    }
    return ceil;
}

int main()
{
    TreeNode* root=NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 15);
    PrintTree(root);
    cout<<"\n";
    cout<<findCeil(root, 8)<<endl;
    cout<<findFloor(root, 21)<<endl;
    return 0;
}
