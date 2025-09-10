#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    unordered_map<long long int,long long int>mp;
    long long int sum=0;
    mp[0]=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
       sum+=arr[i];
       if(mp.find(sum-m)!=mp.end())
       {
        count++;
       }
       mp[sum]++;
           
    }
    cout<<count<<endl;
    
}