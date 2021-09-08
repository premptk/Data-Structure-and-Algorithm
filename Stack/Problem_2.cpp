#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
	stack<int> s;  
	vector<int> v; 

	for(int i=n-1;i>=0;i--)
	{
		if(s.size()==0)
			v.push_back(-1);
		else if(s.size()>0 && s.top()>arr[i])
			v.push_back(s.top());
		else if(s.size()>0 && s.top()<=arr[i])
		{
			while(s.size()>0 && s.top() <= arr[i])
			{
				s.pop();
			}
			if(s.size()==0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(arr[i]);
	}

	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	int arr[] = {7,13,6,12};  // 13,-1,12,-1
	n = sizeof(arr)/sizeof(arr[0]);
	solve(arr,n);
	return 0;
}
