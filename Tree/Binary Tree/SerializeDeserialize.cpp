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

void PrintTree(TreeNode* root)
{
    if(root==NULL)
        return;
    PrintTree(root->left);
    cout<<root->data<<" ";
    PrintTree(root->right);
}


string Serialize(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    string str="";
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        if(node==NULL)
            str.append("#,");
        else
            str.append(to_string(node->data) + ",");
        if(node!=NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return str;
}

TreeNode* Deserialization(string s)
{
    if(s.size()==0) return NULL;

    stringstream str(s);
    string temp;
    getline(str, temp, ',');

    TreeNode* root = new TreeNode(stoi(temp));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        // next string  -- Left
        getline(str, temp, ',');
        if(temp == "#")
        {
            node->left = NULL;
        }
        else{
            TreeNode* leftNode = new TreeNode(stoi(temp));
            node->left = leftNode;
            q.push(node->left);
        }

        // next string  -- Right
        getline(str, temp, ',');
        if(temp == "#")
        {
            node->right = NULL;
        }
        else{
            TreeNode* RightNode = new TreeNode(stoi(temp));
            node->right = RightNode;
            q.push(node->right);
        }
    }
    return root;
}


int main()
{
    TreeNode* root=NULL;
    root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    // root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    // PrintTree(root);
    string str = Serialize(root);
    cout<<str<<endl;
    root = Deserialization(str);
    PrintTree(root);
    return 0;
}
