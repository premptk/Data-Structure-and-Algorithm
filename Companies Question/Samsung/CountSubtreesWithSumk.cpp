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


bool isLeaf(node* root)
{
    if(root->left==NULL && root->right==NULL)
        return true;
    else return false;
}

bool digitsum(node* root, int k)
{
    int num = root->data;
    int sum=0;
    while(num!=0)
    {
        sum += num%10;
        num = num/10;
    }
    if(sum==k)
        return true;
    return false;
}

bool countTrees(node* root, int k, int& cnt)
{
    if(root==NULL)
        return 0;
    bool lb = countTrees(root->left, k, cnt);
    bool rb = countTrees(root->right,k,cnt);
    if(root->left==NULL && root->right==NULL)
    {
        if(digitsum(root,k)){
            cnt++;
            return true;
        }
    }
    else
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            if(lb && rb && digitsum(root,k)){
                cnt++;
                return true;
            }
            else
                return false;
        }
        else if(root->left==NULL && rb)
        {
            cnt++;
            return true;   
        }
        else if(root->right==NULL && lb)
        {
            cnt++;
            return true;
        }
    }
    return false;
}

int CountSubTrees(node* root, int k)
{
    //postorder
    int cnt=0;
    countTrees(root,k,cnt);
    return cnt;
}


int main()
{
    node* root=NULL;
    root = new node(12);
    root->left = new node(22);
    root->left->left = new node(40);
    root->left->left->left = new node(4);
    root->left->left->right = new node(13);
    root->left->right = new node(112);
    root->right = new node(16);
    root->right->left = new node(31);
    root->right->right = new node(23);
    inorder(root);
    cout<<"\n";
    cout<<CountSubTrees(root,4);
    return 0;
}
