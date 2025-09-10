#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());

    long long smallest_missing = 1;
    for (int c : coins) {
        if (c > smallest_missing) break;
        smallest_missing += c;
    }

    cout << smallest_missing << "\n";
}
