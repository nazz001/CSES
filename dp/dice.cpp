#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
long long int solve(int n,vector<long long int>&dp)
{
    if(n<0)
    return 0;
    if(n==0)
    return 1;
    if(dp[n]!=-1)
    return dp[n];
    long long int first=solve(n-1,dp)%MOD;
    long long int second=solve(n-2,dp)%MOD;
    long long int third=solve(n-3,dp)%MOD;
    long long int fourth=solve(n-4,dp)%MOD;
    long long int fifth=solve(n-5,dp)%MOD;
    long long int sixth=solve(n-6,dp)%MOD;
    return dp[n]=(first+second+third+fourth+fifth+sixth)%MOD;
}

int main()
{
    int n;
     cin>>n;
    vector<long long int>dp(n+1,-1);
    
   
    long long int ans=solve(n,dp);
    cout<<ans%MOD<<endl;
    return 0;
}