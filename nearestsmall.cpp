#include <bits/stdc++.h>
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
    stack<int>st;
    vector<int>ans(n,0);
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty()&&arr[st.top()]>arr[i])
        {
            int index=st.top();
            st.pop();
            ans[index]=i+1;
        }
        st.push(i);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}