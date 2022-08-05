#include<bits/stdc++.h>
using namespace std;

struct node
{
  node *links[26];
  bool flag = false;
  int cnt = 0;
  int cntEnd = 0;

  bool containsKey(char ch)
  {
    return (links[ch-'a'] != NULL);
  }

  void putKey(char ch, node* temp)
  {
    links[ch-'a'] = temp;
  }

  node* getKey(char ch)
  {
    return links[ch-'a'];
  }

  void setEndFlag()
  {
    flag=true;
  }

  bool isEnd()
  {
    return flag;
  }

  void increasecnt()
  {
    cnt++;
  }

  void increaseEndcnt()
  {
    cntEnd++;
  }
};



class Node
{
  node* root;
  
  public:
    Node(){
      root = new node();
    }


    void insert(string str)
    {
      node* temp = root;
      for(int i=0;i<str.size();i++)
      {
        if(!temp->containsKey(str[i]))
        {
          temp->putKey(str[i], new node());
        }
        temp = temp->getKey(str[i]);
        temp->increasecnt();
      }
      temp->setEndFlag();
      temp->increaseEndcnt();
      cout<<str<<" Inserted! \n";
    }


    bool startsWith(string str)
    {
      node* temp = root;
      for(int i=0;i<str.size();i++)
      {
        if(!temp->containsKey(str[i]))
        {
          return false;
        }
        temp = temp->getKey(str[i]);
      }
      return true;
    }


    bool search(string str)
    {
      node* temp = root;
      for(int i=0;i<str.size();i++)
      {
        if(temp->containsKey(str[i]))
        {
          temp = temp->getKey(str[i]);
        }
        else
          return 0;
      }
      return temp->isEnd();
    }


    int countWordEqualTo(string str)
    {
      node* temp = root;
      for(int i=0;i<str.size();i++)
      {
        if(!temp->containsKey(str[i]))
        {
          return -1;
        }
        temp = temp->getKey(str[i]);
      }
      return temp->cntEnd;
    }

    int countWordsStartingWith(string str)
    {
      node* temp = root;
      for(int i=0;i<str.size();i++)
      {
        if(temp->containsKey(str[i]))
        {
          temp = temp->getKey(str[i]);
        }
        else return 0;
      }
      return temp->cnt;
    }
};

int main()
{
  Node obj;
  vector<string> arr = {"nin", "ninj", "ninja", "ni", "n", "b"};
  
  int minlen = INT_MAX;
  for(auto &it : arr){
    obj.insert(it);
    minlen = min(minlen, (int)it.size());
  }

  string ans = arr[0].substr(0, minlen);
  bool flag = true;
  while(ans.size()>0 && flag)
  {
    if(obj.countWordsStartingWith(ans) != arr.size())
      minlen--;
    else
      flag = false;
    ans = arr[0].substr(0, minlen);
  }
  cout<<"Prefix : "<<ans<<endl;
  return 0;
}
