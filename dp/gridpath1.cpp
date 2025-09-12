#include<bits/stdc++.h>
using namespace std;

// int ans=0;
int MOD=1e9+7;
int t[1001][1001];
int solve(vector<vector<char>>&arr,int i,int j,int n)
{
    if(i==n-1&&j==n-1)
    {
        // ans++;
        return 1;
    }
    if(i>n||j>n) return 0;int ans=0;
    if(t[i][j]!=-1) return t[i][j];
    if(i+1<n&&arr[i+1][j]=='.')
    {
        ans+=solve(arr,i+1,j,n);
        ans=ans%MOD;

    }
    if(j+1<n&&arr[i][j+1]=='.')
    {
    ans+=solve(arr,i,j+1,n);
    ans=ans%MOD;
    }
    return t[i][j]=ans;

}
int main()

{
    int n;
    cin>>n;
    vector<vector<char>>arr(n,vector<char>(n,'.'));
    // solve()
    memset(t,-1,sizeof(t));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    if(arr[0][0]=='*'){ cout<<0; return 0;}
    int good= solve(arr,0,0,n);
    cout<<good%MOD<<endl;
    return 0;

}