#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    // ----------------------grahh input done----------------------
    vector<int>parent(n,-1);
    vector<int>distance(n,INT_MAX);
    queue<int>q;
    q.push(0);
    distance[0]=0;
    parent[0]=-1;
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto child:adj[node])
        {
            if(distance[child]==INT_MAX)
            {
                distance[child]=1+distance[node];
                parent[child]=node;
                q.push(child);
            }
        }
    }
    if(distance[n-1]==INT_MAX)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<distance[n-1]+1<<endl;
    int index=n-1;
    vector<int>ans;
    // cout<<n<<" ";
    ans.push_back(n);
    while(parent[index]!=-1)
    {
        ans.push_back(parent[index]+1);
        index=parent[index];
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)
    cout<<x<<" ";
    cout<<endl;

}