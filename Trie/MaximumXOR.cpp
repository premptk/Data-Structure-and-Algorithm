#include<bits/stdc++.h>
using namespace std;

struct node
{
  node *links[2];
  bool containsBit(int bit)
  {
    return (links[bit]!=NULL);
  }

  void putBit(int bit, node* temp)
  {
    links[bit] = temp;
  }

  node* getBit(int bit)
  {
    return links[bit];
  }
};



class Node
{
  node* root;

  public:
    Node(){
      root = new node();
    }

    void insert_bits(int num)
    {
      node* temp = root;
      for(int i=31;i>=0;i--)
      {
        int bit = (num>>i) & 1;
        if(!temp->containsBit(bit))
        {
          temp->putBit(bit, new node());
        }
        temp = temp->getBit(bit);
      }
    }

    int maximumXOR(int num)
    {
      node* temp = root;
      int maxi = 0;
      for(int i=31;i>=0;i--)
      {
        int bit = (num>>i) & 1;
        if(temp->containsBit(1-bit))
        {
          maxi = maxi | (1<<i);
          temp->putBit(bit, new node());
        }
        else
        {
          temp = temp->getBit(bit);
        }
      }
      return maxi;
    }

};


int MaxXOR()
{
  Node root;
  vector<int> arr1 = {9,8,7,6,2}, arr2 = {4,3,6,1};
  for(auto &it : arr1)
    root.insert_bits(it);
  
  int maxi = 0;
  for(auto &it: arr2)
    maxi = max(maxi, root.maximumXOR(it));

  return maxi;
}


int main()
{
  
  cout<<MaxXOR();
  return 0;
}
