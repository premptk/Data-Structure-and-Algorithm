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

int maxDepth(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh,rh);
}

int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }

bool isBalanced(TreeNode* root) {
        return dfsHeight (root) != -1;
}

int main()
{
    TreeNode* root=NULL;
    root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->right = new TreeNode(40);
    root->left->right->right = new TreeNode(50);
    root->left->right->right->right = new TreeNode(60);
    cout<<maxDepth(root)<<endl;
    cout<<isBalanced(root)<<endl;
    return 0;
}
