#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
vector<int>r;

int find(int element)
{
    if(parent[element]==element) return element;
    return parent[element]=find(parent[element]);
}
void uni(int node1,int node2)
{
    int parent1=find(node1);
    int parent2=find(node2);
    if(parent1==parent2) return;
    if(r[parent1]>r[parent2])
    {
        parent[parent2]=parent1;
    }
    else if(r[parent1]<r[parent2])
    {
        parent[parent1]=parent2;
    }
    else
    {
        parent[parent2]=parent1;
        r[parent1]++;
    }
   
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>edges(m);
    for(int i=0;i<m;i++)
    {
        cin>>edges[i].first>>edges[i].second;
    }
    parent.resize(n+1);
    r.resize(n+1,0);
    for(int i=1;i<=n;i++)
    parent[i]=i;
    for(int i=0;i<m;i++)
    {
        uni(edges[i].first,edges[i].second);
    }
    // set<pair>s;
    vector<pair<int,int>>ans;
    int count=0;
    for(int i=1;i<n;i++)
    {
        int parent1=find(i);
        int parent2=find(i+1);
        if(parent1!=parent2)
        {
            count++;
            ans.push_back({i,i+1});
            uni(parent1,parent2);
        }

    }
    cout<<count<<endl;
    for(auto x:ans)
    cout<<x.first<<" "<<x.second<<endl;
    return 0;


}