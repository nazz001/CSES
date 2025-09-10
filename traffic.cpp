#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    int n;
    if (!(cin >> x >> n)) return 0;

    vector<ll> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    // S stores positions of lights (always sorted). Start with endpoints 0 and x.
    set<ll> S = {0, x};
    // segs stores lengths of current segments (may have duplicates) so we use multiset.
    multiset<ll> segs = {x};

    // For each insertion, find the segment [l, r] that contains p[i],
    // remove length (r-l) from segs, insert (p-l) and (r-p), and insert p into S.
    for (int i = 0; i < n; ++i) {
        ll pos = p[i];

        // it points to the first element >= pos in S.
        auto it = S.lower_bound(pos);
        ll r = *it;
        ll l = *prev(it);

        // remove one instance of the old segment length (r - l)
        auto oldIt = segs.find(r - l);
        if (oldIt != segs.end()) segs.erase(oldIt);

        // insert the two new segments
        segs.insert(pos - l);
        segs.insert(r - pos);

        // add the new traffic light
        S.insert(pos);

        // largest gap is the last element in multiset
        cout << *segs.rbegin();
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}
