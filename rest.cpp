#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>cust;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        cust.push_back({x,y});
    }
    sort(cust.begin(),cust.end());
    // priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>pq;
    int count=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int start=cust[i].first;
        int end=cust[i].second;
        while(!pq.empty()&&pq.top()<=start)
        {
            pq.pop();
        }
        count=max(count,(int)pq.size()+1);
        pq.push(end);
    }
    cout<<count<<endl;
    return 0;


    }

