#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    node(int x)
    {
        data = x;
        left=NULL;
        right=NULL;
    }
};

void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* overlap(node* root1, node* root2)
{
    if(root1==NULL && root2==NULL)
        return NULL;
    else if(root1==NULL && root2!=NULL)
        return root2;
    else if(root1!=NULL && root2==NULL)
        return root1;
    else
    {
        // both have values
        root1->data = root2->data;   
    }
    root1->left = overlap(root1->left, root2->left);
    root2->right = overlap(root1->right, root2->right);
    return root1;
}

int main()
{
    node *root1=NULL,*root2=NULL;
    root1 = new node(1);
    root1->left = new node(2);
    root1->left->left=new node(4);
    root1->left->right = new node(5);
    root1->right=new node(3);
    root1->right->left=new node(6);
    root1->right->right=new node(7);

    root2 = new node(5);
    root2->left = new node(9);
    root2->left->right=new node(1);
    root2->right=new node(8);
    root2->right->left=new node(6);

    node* root = overlap(root1, root2);
    inorder(root1);
    return 0;
}
