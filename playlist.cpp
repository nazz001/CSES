#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        
        // arr[i]=x;
        cin>>arr[i];
    }
    unordered_map<int,int>umap;
    int i=0;
    int j=0;
    int count=0;
    // vector<int>
    while(j<n)
    {
       if(umap[arr[j]]>=i&&umap.find(arr[j])!=umap.end())
       {
        int index=umap[arr[j]];
        int newE=arr[index+1];
        i=index+1;
        umap[arr[j]]=j;
       
       }
       else
       {
        umap[arr[j]]=j;
        count=max(count,j-i+1);
       }
       j++;
     
    }
    cout<<count<<endl;
    return 0;
 }

