#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++)
    {
       int x;
       cin>>x;
       arr[i]={x,i};
    }
    sort(arr.begin(),arr.end());
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
    // }
    // cout<<e/ndl;
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            int sum=arr[i].first+arr[j].first+arr[k].first;
            // cout<<sum<<" ";
            if(sum==m)
            {
                cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<arr[k].second+1<<endl;
                return 0;
            }
            else if(sum>m)
            {
                k--;
            }
            else
                j++;

        }
    }
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }




