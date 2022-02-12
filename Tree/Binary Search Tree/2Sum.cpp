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


node* insert(node* root, int x)
{
    if(root==NULL)
        return new node(x);
    else if(root->data > x)
        root->left = insert(root->left, x);
    else if(root->data < x)
        root->right = insert(root->right, x);
    return root;
}


class BSTIterator {
    stack<node *> myStack;
    bool reverse = true; 
public:
    BSTIterator(node *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        node *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->data;
    }

private:
    void pushAll(node *root) {
        for(;root != NULL; ) {
             myStack.push(root);
             if(reverse == true) {
                 root = root->right; 
             } else {
                 root = root->left; 
             }
        }
    }
};

bool TwoSum(node* root, int key)
{
    BSTIterator l(root, false);
    BSTIterator r(root, true);
    int i = l.next();
    int j = r.next();
    while(i<j)
    {
        if(i+j == key)
            return true;
        else if(i+j < key)
            i = l.next();
        else j = r.next();
    }
    return false;
}

int main()
{
    node* root=NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 6);
    inorder(root);
    cout<<"\n";
    cout<<TwoSum(root, 14);
    return 0;
}
