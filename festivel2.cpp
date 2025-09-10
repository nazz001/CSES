#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    if (!(cin >> n >> m)) return 0;
    vector<pair<long long,long long>> a(n);
    for (long long i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

    // sort by end time (then by start for stability)
    sort(a.begin(), a.end(), [](const pair<long long,long long>& x, const pair<long long,long long>& y){
        if (x.second != y.second) return x.second < y.second;
        return x.first < y.first;
    });

    multiset<long long> watchers; // stores end times of last movie for each watcher
    long long ans = 0;

    for (auto &mv : a) {
        long long start = mv.first;
        long long end   = mv.second;

        // find first element > start
        auto it = watchers.upper_bound(start);
        if (it == watchers.begin()) {
            // no watcher with end <= start
            if ((long long)watchers.size() < m) {
                // allocate new watcher
                watchers.insert(end);
                ++ans;
            }
            // otherwise skip movie
        } else {
            // reuse watcher with largest end <= start
            --it;
            watchers.erase(it);
            watchers.insert(end);
            ++ans;
        }
    }

    cout << ans << '\n';
    return 0;
}
