#include<bits/stdc++.h>
using namespace std;


// Naive Approach => O(n^2)
// void solve(int arr[], int n)
// {
// 	int span[n];
// 	int num;
// 	for(int i=0;i<n;i++)
// 	{
// 		num=1;
// 		for(int j=i;j>=0;j--)
// 		{
// 			if(arr[j] > arr[i])
// 				break;
// 			else if(arr[j] < arr[i])
// 				num++;
// 		}
// 		span[i] = num;
// 	}

// 	for(int i=0;i<n;i++)
// 		cout<<span[i]<<" ";
// }

void solve(int arr[], int n)
{
	// Efficient Approach => O(n)
	int span[n];
	stack<int> s;
	s.push(0); // starting will always be 0
	span[0] = 1;
	for(int i=1;i<n;i++)
	{
		if(s.empty())
			span[i] = i+1;

		while(!s.empty() && arr[i] > arr[s.top()])
			s.pop();

		if(!s.empty())
			span[i] = i - s.top();
		
		s.push(i);		
	}
	//printing span 
	for(int i=0;i<n;i++)
		cout<<span[i]<<" ";
}


int main()
{
	int n;
	int arr[]={100, 80, 60, 70, 60, 75, 85};
	n = sizeof(arr)/sizeof(arr[0]);
	solve(arr,n);
	return 0;
}
