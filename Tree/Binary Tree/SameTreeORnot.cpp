#include<iostream>
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

bool isSame(TreeNode* root1, TreeNode* root2)
{
    if(root1==NULL || root2==NULL)
        return(root1==root2);
    return root1->data==root2->data 
    && isSame(root1->left, root2->right) 
    && isSame(root1->right, root2->right);
}

int main()
{
    TreeNode* root=NULL;
    TreeNode* root2=NULL;
    root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->right = new TreeNode(40);
    root->left->right->left = new TreeNode(45);
    root->left->right->right = new TreeNode(50);
    root->left->right->right->right = new TreeNode(60);

    cout<<isSame(root,root2)<<endl;
    return 0;
}
