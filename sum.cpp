#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  n,x;
    cin>>n>>x;
    // for()
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        arr.push_back({y,i});
      
    }
    sort(arr.begin(),arr.end());
    int i=0;
    int j=n-1;
    while(i<j)
    {
        int sum=arr[i].first+arr[j].first;
        if(sum==x)
        {
            cout<<arr[i].second+1<<" "<<arr[j].second+1<<endl;
            return 0;
        }
        else if(sum<x)
        {
            i++;
        }
        else{
            j--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
   
    
}