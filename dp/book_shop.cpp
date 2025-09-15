#include<bits/stdc++.h>
using namespace std;
// int solve(vector<pair<int,int>>&arr,int index,int x)
// {
//     if(index>arr.size()) return 0;
//     if(x==0) return 0;
//     if(x<0) return INT_MIN;
//     // int take
//     // int not_take
//     int not_take=solve(arr,index+1,x);
//     int take=INT_MIN;
//     int good=solve(arr,index+1,x-arr[index].first);
//     if(good!=INT_MIN)
//     take=max(take,good+arr[index].second);
//     return max(take,not_take);
// }

// int solve(vector<int>&cost,vector<int>&page,int index,int x,vector<vector<int>>&dp)
// {
//     if(x<0)return INT_MIN;
//     if(index>=cost.size()) return 0;
//     if(x==0)return 0;

//     // int take
//     // int not_take
//     if(dp[index][x]!=-1) return dp[index][x];
//     int not_take=solve(cost,page,index+1,x,dp);
//     int take=INT_MIN;
//     int good=solve(cost,page,index+1,x-cost[index],dp);
//     if(good!=INT_MIN)
//     take=max(take,good+page[index]);
//     return dp[index][x]=max(take,not_take);
// }
int main()
{
    int n,x;
    cin>>n>>x;
    // vector<pair<int,int>>arr(n);
    vector<int>cost(n);
    vector<int>page(n);
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    for(int i=0;i<n;i++)
    cin>>page[i];
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<x+1;j++)
        {
            if(i==0||j==0)
            {
            dp[i][j]=0;
            continue;
            }
            if(cost[i]>j)
            dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=max(dp[i-1][j],page[i]+(j-cost[i]>=0?dp[i][j-cost[i]]:0          ));
            }
            

        }
    }
    cout<<dp[n][x]<<endl;


    
    return 0;
}