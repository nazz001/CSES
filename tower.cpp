#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>keeper;
    // for(int i=)
    for(int i=0;i<n;i++)
    {
        if(keeper.empty())
        {
            keeper.push_back(arr[i]);
            continue;   
        }
        auto it=upper_bound(keeper.begin(),keeper.end(),arr[i]);
        if(it==keeper.end())
        {
            keeper.push_back(arr[i]);
        }
        else
        {
            int index=it-keeper.begin();
            keeper[index]=arr[i];
        }


    }
    cout<<keeper.size()<<endl;    return 0;
    
}

