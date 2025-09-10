#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int get=v[v.size()/2];
    long long int sum=0;;
    for(int i=0;i<v.size();i++)
    {
        sum+=abs(v[i]-get);
    }
    cout<<sum<<endl;
}