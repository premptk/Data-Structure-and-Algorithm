#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *link[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (link[ch-'a']!=NULL);
    }

    void put(char ch, node* temp)
    {
        link[ch - 'a'] = temp;
    }

    node *get(char ch)
    {
        return link[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    node* root;
    public:
        Trie()
        {
            root = new node();
        }

        void insert(string word)
        {
            node* temp = root;
            for(int i=0;i<word.size();++i)
            {
                if(!temp->containsKey(word[i]))
                {
                    temp->put(word[i], new node());
                }
                temp = temp->get(word[i]);
            }
            temp->setEnd();
        }

        bool search(string word)
        {
            node* temp = root;
            for(int i=0;i<word.size();++i)
            {
                if(!temp->containsKey(word[i]))
                    return false;
                temp = temp->get(word[i]);
            }
            return temp->isEnd();
        }

        bool startsWith(string word)
        {
            node* temp = root;
            for(int i=0;i<word.size();++i)
            {
                if(!temp->containsKey(word[i]))
                    return false;
                temp = temp->get(word[i]);
            }
            return true;
        }
};

int main()
{
    Trie obj;
    string str = "prem", str1 = "pre";
    obj.insert(str);
    cout<<obj.startsWith(str1);
    return 0;
}
