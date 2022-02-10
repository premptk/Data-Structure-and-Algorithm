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

int kthSmallest(TreeNode* root, int k)
{
    int cnt=0;
    if(root==NULL){
        cout<<"Empty Tree!";
        return -1;
    }
    TreeNode* cur=root;
    while(cur!=NULL)
    {
        if(cur->left==NULL){
            cnt++;
            if(cnt == k)
                return cur->data;
            cur = cur->right;
        }
        else
        {
            TreeNode* prev = cur->left;
            while(prev->right!=NULL && prev->right!=cur)
                prev = prev->right;
            if(prev->right==NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cnt++;
                if(cnt == k)
                    return cur->data;
                cur = cur->right;
            }
        }        
    }
    return -1;
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
    cout<<kthSmallest(root, 4)<<endl;
    return 0;
}
