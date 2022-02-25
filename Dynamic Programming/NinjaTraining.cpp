#include<bits/stdc++.h>
using namespace std;


// Recursive Approach
int func(int day, int last, vector<vector<int>> &points)
{
    if(day==0)
    {
        int maxi=0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
                maxi = max(maxi,points[0][i]);
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            int profit = points[day][i] + func(day-1,i,points);
            maxi = max(maxi, profit);
        }
    }
    return maxi;
}


// Memoization
int func2(int day, int last, vector<vector<int>> &points, vector<vector<int>> dp)
{
    if(day==0)
    {
        int maxi=0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                maxi = max(points[0][i], maxi);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=0)  
        return dp[day][last];
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            int profit = points[day][i] + func2(day-1, i, points, dp);
            maxi = max(maxi,profit);
        }
    }
    return dp[day][last] = maxi;
}


// Tabulation
int func3(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp (4, vector<int> (3,0));
    //Base case
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2],points[0][0]));

    for(int day=1;day<n;day++) // 1 to n-1
    {
        for(int last=0;last<4;last++)
        {
            dp[day][last]=0;
            int maxi=0;
            for(int i=0;i<3;i++)
            {
                if(i!=last)
                {
                    int point = points[day][i] + dp[day-1][i];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }
    return dp[n-1][3];
}


// Memoization - Space Optimization
int func4(int n, vector<vector<int>> &points)
{
    vector<int> prev(4,0);
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max(points[0][1], max(points[0][2],points[0][0]));

    for(int day=1;day<n;day++)
    {
        vector<int> temp(4,0);
        for(int last=0;last<4;last++)
        {
            temp[last]=0;
            for(int i=0;i<3;i++)
            {
                if(i!=last)
                    temp[last] = max(temp[last], points[day][i] + prev[i]);
            }
        }
        prev = temp;
    }
    return prev[3];
}

int main()
{
    vector<vector<int>> points = {{2,1,3}, {3,4,6}, {10,1,6}, {8,3,7}};
    cout<<func(3,3,points)<<endl;
    vector<vector<int>> dp (4, vector<int> (3,0));
    cout<<func2(3,3,points, dp)<<endl;
    cout<<func3(4,points)<<endl;
    cout<<func4(4,points)<<endl;
    return 0;
}
