#include<iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
    node(int x)
    {
        data=x;
        left=right=NULL;
    }
};

int main()
{
    node* root=NULL;
    root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    return 0;
}
