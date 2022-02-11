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

void PrintTree(TreeNode* root)
{
    if(root==NULL)
        return;
    PrintTree(root->left);
    cout<<root->data<<" ";
    PrintTree(root->right);
}

TreeNode* Successor(TreeNode* root, int key)
{
    TreeNode* succ = NULL;
    while(root!=NULL)
    {
        if(root->data <= key)
            root = root->right;
        else{
            succ = root;
            root = root->left;
        }
    }
    return succ;
}

TreeNode* Predeccesor(TreeNode* root, int key)
{
    TreeNode* pred = NULL;
    while(root!=NULL)
    {
        if(root->data >= key)
            root = root->left;
        else
        {
            pred = root;
            root = root->right;   
        }        
    }
    return pred;
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
    root = insert(root, 3);
    root = insert(root, 6);
    PrintTree(root);
    cout<<"\n";
    cout<<Successor(root,15)->data<<endl;
    cout<<Predeccesor(root,15)->data<<endl;
    return 0;
}
