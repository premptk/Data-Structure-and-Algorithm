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

int MaxWidth(TreeNode* root)
{
    queue<pair<TreeNode*, int>> q;
    map<TreeNode*, int> mp;
    q.push({root,0});
    int ans=1,first,last;
    while(!q.empty())
    {
        int size=q.size();
        int mmin = q.front().second;
        for(int i=0;i<size;i++)
        {
            int curid = q.front().second-mmin;
            auto nd = q.front().first;
            q.pop();
            if(i==0)
                first = curid;
            if(i==size-1)
                last=curid;
            if(nd->left)
                q.push({nd->left, curid*2+1});
            if(nd->right)
                q.push({nd->right, curid*2+2});

        }
        ans = max(ans, last-first+1);
    }
    return ans;
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
   root->right->right->right = new TreeNode(42);
   root->left->left->left = new TreeNode(23);
   inorder(root);
   cout<<"\n";
   cout<<MaxWidth(root);
   return 0;
}
