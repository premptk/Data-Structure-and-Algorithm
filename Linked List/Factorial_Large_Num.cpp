#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next = NULL;
    }
};

void Multiply(node* root, int i)
{
    int carry=0;
    int d = i;
    node *temp, *prev;
    prev=temp=root;
    while(temp!=NULL)
    {
        d = temp->data * i + carry;
        temp->data = d%10;
        carry = d/10;
        prev = temp;
        temp = temp->next;
    }

    while(carry!=0)
    {
        prev->next = new node((int) carry%10);
        carry = carry/10;
        temp = prev->next;
        temp = temp->next;
        prev = prev->next;
    }
}

void print(node* root)
{
    if(root==NULL)
        return;
    print(root->next);
    cout<<root->data<<" ";
}

int main()
{
    node* root=NULL;
    root = new node(1);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
        Multiply(root,i);
    print(root);
    return 0;
}
