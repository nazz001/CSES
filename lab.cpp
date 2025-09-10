#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    queue<pair<int,int>>q;
    pair<int,int>end;
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='A')
            {
                q.push({i,j});
                parent[i][j]={i,j};
            }
            if(arr[i][j]=='B')
            {
                end={i,j};
            }
        }
    }
    int level=0;
    while(!q.empty())
    {

        int n=q.size();
        while(n--)
        {
            auto [i,j]=q.front();
            q.pop();
            int row[4]={-1,0,1,0};
            int col[4]={0,1,0,-1};
            if(arr[i][j]==
            'B')
        {
            cout<<"YES"<<endl;
            cout<<level<<endl;
            vector<char>path;
            int first=i;
            int second=j;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<parent[i][j].first<<" "<<parent[i][j].second<<"   ";
                }
                cout<<endl;
            }
          break;
            

        }
            for(int k=0;k<4;k++)
            {
                int newRow=i+row[k];
                int newCol=j+col[k];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m&& arr[newRow][newCol]!='#' && parent[newRow][newCol].first==-1)
                {
                    parent[newRow][newCol]={i,j};
                    q.push({newRow,newCol});
                    
                }
            }
        }
        level++;







        }

    }








}