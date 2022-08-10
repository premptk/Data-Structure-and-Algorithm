#include<bits/stdc++.h>
using namespace std;

struct node
{
  node *links[26];
  bool flag = false;

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
};


int DistinctSubstring(string str)
{
  node* root = new node();
  int cnt=0;
  int n = str.size();
  for(int i=0;i<n;i++)
  {
    node* temp = root;    
    for(int j=i;j<n;j++)
    {
        if(!temp->containsKey(str[i]))
        {
          cnt++;
          temp->putKey(str[i], new node());
        }
        temp = temp->getKey(str[i]);
    }
  }
  return cnt;
}

int main()
{
  
  string str = "sds";
  cout<<DistinctSubstring(str);
  return 0;
}
