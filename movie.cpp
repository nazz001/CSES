#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> movie(n);

    for (int i = 0; i < n; i++) {
        cin >> movie[i].first >> movie[i].second;
    }

    sort(movie.begin(), movie.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        return a.second < b.second;
    });
    int count=0;
    int keeper=INT_MIN;
    for(int i=0;i<movie.size();i++)
    {
        int first=movie[i].first;
        int second=movie[i].second;
        if(keeper<=first)
        {
            count++;
            keeper=max(keeper,second);
        }
        
        
        
    }
    cout<<count;

}
