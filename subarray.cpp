#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    long long int max_sum=LONG_LONG_MIN;
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        max_sum=max(max_sum,sum);
        if(sum<0)
        {
            sum=0;
        }
    }
    cout<<max_sum<<endl;
}