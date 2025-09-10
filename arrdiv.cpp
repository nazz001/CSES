#include <bits/stdc++.h>
using namespace std;

int calc(const vector<int>& arr, long long element, int group) {
    int current = 0;
    long long page = 0;
    for (int i = 0; i < (int)arr.size(); ++i) {
        if (page + arr[i] > element) {
            current++;
            page = arr[i];
        } else {
            page += arr[i];
        }
    }
    if (page) current++;

    if (current == group) return 1;   // exactly group partitions used
    if (current > group)  return 0;   // need more partitions -> mid too small
    return 2;                         // used fewer partitions -> mid is large enough
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    long long start = 0;
    long long end = 0;
    for (int x : arr) {
        start = max(start, 1LL * x); // minimal feasible value is max element
        end += x;
    }

    long long ans = end;
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        int good = calc(arr, mid, m);

        if (good == 0) {
            // need more partitions than allowed -> mid too small
            start = mid + 1;
        } else {
            // both good==1 (exact) and good==2 (fewer used) mean mid is feasible
            ans = mid;
            end = mid - 1; // try smaller
        }
    }

    cout << ans << '\n';
    return 0;
}
