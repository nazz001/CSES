#include<bits/stdc++.h>
using namespace std;
int solve(int x,vector<int>&dp)
{
    if(x<0)
    return INT_MAX;
    if(x==0) return 0;
    int n=x;
    int ans=INT_MAX;
    // cout<<x<<" ";
    if(dp[x]!=-1 ) return dp[x];

    while(n)
    {
        int rem=n%10;
        n=n/10;
        if(rem==0) continue;
        if(rem>x) continue;;
        int good=solve(x-rem,dp);
        if(good!=INT_MAX)
        ans=min(ans,1+good);
        

    }
    return dp[x]=ans;


}
int main()
{
    int x;
    cin>>x;
    vector<int>dp(x+1,-1);
    cout<<solve(x,dp)<<endl;
    return 0;
}