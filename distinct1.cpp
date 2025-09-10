#include<bits/stdc++.h>
using namespace std;
// int MOD=1e9+7;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    unordered_map<int,int>umap;
    int i=0;
    int j=0;
    long long int count=0;
    // int sum=0;
    long long int ans=0;
    while(j<n)
    {
        count++;
        umap[arr[j]]++;
        while(umap[arr[j]]>1)
        {
            umap[arr[i]]--;
            i++;
            count--;

        }
        ans+=count;
        // ans=ans
        j++;

    }
    cout<<ans<<endl;
    return 0;

}