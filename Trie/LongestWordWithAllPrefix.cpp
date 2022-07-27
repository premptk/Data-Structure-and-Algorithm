#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *link[26];
    bool flag = false;
    int cntPrefix = 0;
    int cntEndWith = 0;

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
                    temp->put(word[i], new node());

                temp = temp->get(word[i]);
            }
            temp->setEnd();
        }

        bool hasAllPrefix(string &word)
        {
            node* temp = root;
            for(int i=0;i<word.size();++i)
            {
                if(temp->containsKey(word[i])){
                    temp = temp->get(word[i]);
                    if(temp->isEnd()==false)
                        return false;
                }
                else
                    return false; 
            }
            return true;
        }
};

int main()
{
    vector<string> arr = {"n", "ni", "ninja", "ninj", "ninga","nin"};
    Trie obj;
    for(auto &it : arr)
        obj.insert(it);
    
    string longest = "";
    for(int i=0;i<arr.size();++i)
    {
        if(obj.hasAllPrefix(arr[i]))
        {
            if(longest.size() == arr[i].size() && longest > arr[i])
                    longest = arr[i];

            else if(longest.size()<arr[i].size())
                longest = arr[i];
        }
    }
    if(longest == "") cout<<"None";
    else cout<<longest<<endl;
    return 0;
}
