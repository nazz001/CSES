#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> pos(n+1);  // store positions

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i; // position of number arr[i]
    }

    int rounds = 1; // at least one round
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i-1]) {
            rounds++; // need a new round
        }
    }

    cout << rounds << "\n";
}
