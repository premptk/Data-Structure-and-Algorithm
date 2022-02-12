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
stack<TreeNode*> st;

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

bool hasNext()
{
    return !st.empty();
}

void AllLeft(TreeNode* root)
{
    while(root!=NULL)
    {
        st.push(root);
        root = root->left;
    }
}

int Next()
{
    if(hasNext())
    {
        auto node = st.top();
        st.pop();
        AllLeft(node->right);
        return node->data;
    }
    return -1;
}

void BSTiterator(TreeNode* root)
{
    st.push(root);
    AllLeft(root->left);
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
    BSTiterator(root);
    cout<<hasNext()<<endl;
    cout<<Next()<<endl;
    cout<<Next()<<endl;
    cout<<Next()<<endl;
    return 0;
}
