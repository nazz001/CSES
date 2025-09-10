#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, long long> mp;
    long long sum = 0, count = 0;

    mp[0] = 1;  // empty prefix contributes to valid remainder

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        int rem = ((sum % n) + n) % n;  // fix negative modulo
        count += mp[rem];
        mp[rem]++;
    }

    cout << count << endl;
    return 0;
}
