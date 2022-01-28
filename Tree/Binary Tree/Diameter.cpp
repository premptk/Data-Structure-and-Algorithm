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

int Diameter(TreeNode* root, int &diameter)
{
    if(root==NULL)
        return 0;
    int lh = Diameter(root->left,diameter);
    int rh = Diameter(root->right, diameter);
    diameter = max(diameter, lh+rh);
    return max(lh,rh)+1;
}


int MaxPathsum(TreeNode* root, int &maxSum)
{
    if(root==NULL)
        return 0;
    int lsum = max(0, MaxPathsum(root->left,maxSum));
    int rsum = max(0, MaxPathsum(root->right, maxSum));
    maxSum = max(maxSum, lsum + rsum + root->data);
    return max(lsum,rsum) + root->data;
}

int main()
{
    TreeNode* root=NULL;
    root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->right = new TreeNode(40);
    root->left->right->left = new TreeNode(45);
    root->left->right->right = new TreeNode(50);
    root->left->right->right->right = new TreeNode(60);
    int diameter=0;
    Diameter(root,diameter);
    cout<<"Diameter = "<<diameter<<endl;
    int maxSum=INT_MIN;
    cout<<"Maximum Path sum = "<<MaxPathsum(root,maxSum);
    return 0;
}
