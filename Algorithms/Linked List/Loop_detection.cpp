#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};


node* checkLoop(node* head)
{
    if(head==NULL) return head;
    node *slow=head, *fast=head;
    while(slow && fast)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            return slow;
    }
    return NULL;
}

node* LoopStart(node* head)
{
    node* curr = checkLoop(head);
    if(curr==NULL) return NULL;
    node* temp=head;
    while(temp!=curr)
    {
        temp=temp->next;
        curr=curr->next;
    }    
    return temp;
}

int main()
{
    node* head=NULL;
    head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = head->next;   // Loop created manually at second node (20)

    // Floyd's Cycle Detection Algorithm
    node* Loop = LoopStart(head);   
    if(Loop==NULL) cout<<"No loop is present!"<<endl;
    else cout<<"Loop starts from "<<Loop->data<<endl;
    return 0;
}
