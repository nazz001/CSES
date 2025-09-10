#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, vector<vector<int>>& dp, int sum, int i) {
    if (sum == 0) return 0;
    if (sum < 0) return INT_MAX;
    if (i < 0) return INT_MAX;

    if (dp[i][sum] != -1) return dp[i][sum];

    int take = INT_MAX;
    int temp = solve(arr, dp, sum - arr[i], i); // we can take same coin again
    if (temp != INT_MAX) take = 1 + temp;

    int nottake = solve(arr, dp, sum, i - 1);   // move to smaller index

    return dp[i][sum] = min(take, nottake);
}

int main() {
    int n;
    cin >> n;
    int sum;
    cin >> sum;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    int ans = solve(arr, dp, sum, n - 1);

    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    cout << "\n";

    return 0;
}
