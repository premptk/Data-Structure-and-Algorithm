#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left,*right;
    TreeNode(int x)
    {
        data=x;
        left=right=NULL;
    }
};


void preorder(TreeNode* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void inorder(TreeNode* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


void postorder(TreeNode* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


void BFS(TreeNode* root)
{
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int> temp;
        for(int i=0;i<size;i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
            temp.push_back(node->data);
        }
        ans.push_back(temp);
    }

    for(auto it: ans){
        for(auto z:it)
            cout<<z<<" ";
        cout<<"\n";
    }
}


void preorderIterative(TreeNode* root)
{
    if(root==NULL)
        cout<<"Tree is Empty!"<<endl;
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty())
    {
        auto node=st.top();
        st.pop();
        cout<<node->data<<" ";
        if(node->right!=NULL)
            st.push(node->right);

        if(node->left!=NULL)
            st.push(node->left);
    }
}


void inorderIterative(TreeNode* root)
{
    if(root==NULL)
        cout<<"Tree is Empty!";
    stack<TreeNode*> st;
    auto node = root;
    while(true)
    {
        if(node!=NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if(st.empty()==true) break;
            node =st.top();
            st.pop();
            cout<<node->data<<" ";
            node = node->right;
        }
    }
}


void postorderIterative(TreeNode* root)
{
    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* temp;
    while(!st.empty() || curr!=NULL)
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if(temp==NULL)
            {
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp==st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }
            else
                curr = temp;
        }
        
    }
}

void AllTraversal(TreeNode* root)
{
    stack<pair<TreeNode*, int>> st;
    vector<int> pre,in,post;

    st.push({root,1});
    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        if(it.second==1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL)
                st.push({it.first->left,1});
        }

        else if(it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL)
                st.push({it.first->right,1});
        }

        else
        {
            post.push_back(it.first->data);
        }
    }

    cout<<"\nPreorder : ";
    for(auto p : pre)
        cout<<p<<" ";
    
    cout<<"\nInorder : ";
    for(auto i : in)
        cout<<i<<" ";
        
    cout<<"\nPostorder : ";
    for(auto po : post)
        cout<<po<<" ";
}

int main()
{
    TreeNode* root=NULL;
    root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new  TreeNode(32);
    root->left->right = new TreeNode(34);
    root->right->right = new TreeNode(43);
    cout<<"-- BFS --\n";
    BFS(root);
    cout<<"\n -- Recursive -- \n";
    cout<<"Preorder : ";    preorder(root);
    cout<<"\nInorder : ";   inorder(root);
    cout<<"\nPostorder : "; postorder(root);

    cout<<"\n -- Iterative -- \n";
    cout<<"Preorder : ";    preorderIterative(root);
    cout<<"\nInorder : ";   inorderIterative(root);
    cout<<"\nPostorder : "; postorderIterative(root);

    cout<<"\n\n All IN One";
    AllTraversal(root);
    return 0;
}
