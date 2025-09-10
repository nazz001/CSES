// #include<bits/stdc++.h>
// using namespace std;
// int solve(vector<int>&arr,int index,int x,int sum,vector<vector<int>>&dp)
// {
//     if(sum>x)
//     return INT_MAX;
//     if(sum==x) return 0;
//     int take=INT_MAX;
//     if(index>=arr.size())
//     return INT_MAX;
//     if(dp[index][sum]!=-1) return dp[index][sum];
//     int good=solve(arr,index,x,sum+arr[index],dp);
//     if(good!=INT_MAX)
//     take=1+good;
//     int bad=INT_MAX;
//     int not_take=solve(arr,index+1,x,sum,dp);
    
 
//     return dp[index][sum]=min(not_take,take);

// }
// int main()
// {
//     int n,x;
//     cin>>n>>x;vector<int>arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];

//     vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
//     int good=solve(arr,0,x,0,dp);
   
//     good==INT_MAX?cout<<-1:cout<<good;
//     cout<<endl;
//     return 0;



// }




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    const int INF = 1e9;
    vector<int> dp(x + 1, INF);
    dp[0] = 0; // sum=0 needs 0 numbers

    for (int i = 1; i <= x; i++) {
        for (int a : arr) {
            if (i - a >= 0 && dp[i - a] != INF) {
                dp[i] = min(dp[i], dp[i - a] + 1);
            }
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
}
