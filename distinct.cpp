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
    int i=0;
    int j=0;
    map<int,int>umap;long long int ans=0;
    int dist=0;
    
    while(j<n)
    {
        umap[arr[j]]++;
        if(umap[arr[j]]==1)
        {
            dist++;
        }
        while(dist>m)
        {
            umap[arr[i]]--;
            if(umap[arr[i]]==0)
            {
                dist--;
            }
            i++;
        }
        ans+=(j-i+1);
        j++;
    }
    cout<<ans<<endl;
}

