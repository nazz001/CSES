#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>apartment_desire;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        apartment_desire.push_back(x);
    }
    vector<int>apartment_size;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        apartment_size.push_back(x);
    }
    sort(apartment_desire.begin(),apartment_desire.end());
    sort(apartment_size.begin(),apartment_size.end());
    int i=0;
    int j=0;
    int count=0;
    while(i<n&&j<m)
    {
        int req_min=apartment_desire[i]-k;
        int req_max=apartment_desire[i]+k;
        if(req_min<=apartment_size[j]&&apartment_size[j]<=req_max)
        {
            count++;
            i++;
            j++;
        }
        else if(apartment_size[j]<req_min)
        {
            j++;
        }
        else{
            i++;
        }


    }
    cout<<count;
}