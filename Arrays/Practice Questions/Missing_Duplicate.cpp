#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {4,3,6,2,1,1};
    int n = arr.size();
    int sum = 0;
    for(int i=0;i<arr.size();i++)
        sum += arr[i];
    int xy = (n*(n+1))/2 - sum;

    sum=0;
    for(int i=0;i<arr.size();i++)
        sum += (arr[i]*arr[i]);
    int xy2 = (n*(n+1)*(2*n+1))/6 - sum;

    int xyp = xy2/xy;
    int x = (xyp+xy)/2;
    int y = x - xy;
    cout<<"Missing num : "<<x<<"\nDuplicate num : "<<y; 
    return 0;
}
