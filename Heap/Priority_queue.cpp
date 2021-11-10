#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.push(25);
    cout<<"Size = "<<pq.size()<<endl;
    while(pq.empty()==false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }   
    cout<<"\n";

    //Using array
    int arr[] = {2,5,1,6,3};
    priority_queue<int, vector<int>, greater<int>> pa(arr,arr+5);
    while(pa.empty()==false)
    {
        cout<<pa.top()<<" ";
        pa.pop();
    }
    return 0;
}
