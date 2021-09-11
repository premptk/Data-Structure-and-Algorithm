#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
	// Nearest Smaller to Right
	stack<int> st;
	st.push(n-1);
	int nsr[n];
	nsr[n-1] = n;
	for(int i=n-2;i>=0;i--)
	{
		if(st.empty())
			nsr[i]=i+1;
		else if(arr[i] > arr[st.top()])
			nsr[i] = st.top();
		else
		{
			while(!st.empty() && arr[i] < arr[st.top()])
				st.pop();
			if(st.empty())
				nsr[i] = n;
			else
				nsr[i] = st.top();
		}
		st.push(i);
	}

	while(!st.empty())
		st.pop();

	// Nearest smaller to left
	int nsl[n];
	nsl[0]=-1;
	st.push(0);
	for(int i=1;i<n;i++)
	{
		if(st.empty())
		{
			st.push(i+1);
		}
		else if(arr[i] > arr[st.top()])
		{
			nsl[i] = st.top();
		}
		else
		{
			while(!st.empty() && arr[i]<arr[st.top()])
			{
				st.pop();
			}
			if(st.empty())
				nsl[i] = -1;
			else
				nsl[i] = st.top();
		}
		st.push(i);
	}

	// Ans = (Right - Left - 1) x Area
	int ans = (nsr[0] - nsl[0] - 1)*arr[0];
	for(int i=1;i<n;i++)
	{
		ans = max(ans, (nsr[i]-nsl[i]-1)*arr[i]);
	}
	return ans;
}

int main()
{
	int n;
	int arr[] = {2,1,5,6,2,3};
	n = sizeof(arr)/sizeof(arr[0]);
	cout<<solve(arr,n);
	return 0;
}
