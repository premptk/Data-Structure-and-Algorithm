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

    int getEnd()
    {
        return  cntEndWith;
    }

    int getPrefix()
    {
        return cntPrefix;
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
                temp->cntPrefix += 1;
            }
            temp->cntEndWith += 1;
            temp->setEnd();
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

        int countWordsEqualTo(string &word)
        {
            node* temp = root;
            for(int i=0;i<word.size();++i)
            {
                if(temp->containsKey(word[i]))
                {
                    temp = temp->get(word[i]);
                }
                else return 0;
            }
            return temp->getEnd();
        }

        int countWordsStartingWith(string &word)
        {
            node* temp = root;
            for(int i=0;i<word.size();++i)
            {
                if(temp->containsKey(word[i]))
                    temp = temp->get(word[i]);
                else
                    return 0;
            }
            return temp->getPrefix();
        }

        void erase(string &word)
        {
            node* temp = root;
            for(int i=0;i<word.size();++i)
            {
                if(temp->containsKey(word[i])){
                    temp->cntPrefix -= 1;
                    temp = temp->get(word[i]);
                }
                else
                    return;
            }
            temp->cntEndWith -= 1;
        }
};

int main()
{
    Trie obj;
    string str = "pre", str1 = "pre",str2="prerna",str3 = "back" ,str4 = "p";
    obj.insert(str);
    obj.insert(str1);
    obj.insert(str2);
    obj.insert(str3);
    cout<<obj.startsWith(str1)<<endl;
    cout<<obj.countWordsStartingWith(str4)<<endl;
    cout<<obj.countWordsEqualTo(str1)<<endl;
    obj.erase(str1);
    cout<<obj.countWordsEqualTo(str1)<<endl;
    return 0;
}
