#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    int MOD=1e9+7;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
    vector<long long int>dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<=x;i++)
    {
        for(auto it:arr)
        {
            if(i-it>=0)
            {
                dp[i]=(dp[i]+dp[i-it])%MOD;
            }
        }
    }
    cout<<dp[x]%(MOD)<<endl;
    return 0;

}