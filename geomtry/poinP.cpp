// point_in_polygon_fixed.cpp
// Compile: g++ -std=c++17 -O2 -o point_in_polygon_fixed point_in_polygon_fixed.cpp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

// orientation using long long (may overflow on extremely huge inputs)
// returns 0 = collinear, 1 = positive (val > 0), 2 = negative (val < 0)
int ori_ll(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    long long val = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// check if (x3,y3) lies on segment [(x1,y1),(x2,y2)]
bool onSeg_ll(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return x3 >= min(x1,x2) && x3 <= max(x1,x2)
        && y3 >= min(y1,y2) && y3 <= max(y1,y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vpll poly;
    poly.reserve(n);
    for (int i = 0; i < n; ++i) {
        ll x, y; cin >> x >> y;
        poly.emplace_back(x,y);
    }

    vector<pll> queries(m);
    for (int i = 0; i < m; ++i) cin >> queries[i].first >> queries[i].second;

    for (auto &qp : queries) {
        ll qx = qp.first, qy = qp.second;
        bool boundary = false;
        int intersectCount = 0;

        for (int i = 0; i < n; ++i) {
            ll x1 = poly[i].first,  y1 = poly[i].second;
            ll x2 = poly[(i+1)%n].first, y2 = poly[(i+1)%n].second;

            // boundary check: point exactly on edge
            if (ori_ll(x1,y1, x2,y2, qx,qy) == 0 && onSeg_ll(x1,y1, x2,y2, qx,qy)) {
                boundary = true;
                break;
            }

            // skip horizontal edges for intersection counting (they don't change parity here)
            if (y1 == y2) continue;

            // check if horizontal ray at qy crosses the edge vertically
            if ( (y1 > qy) != (y2 > qy) ) {
                // We want to check if intersection x-coordinate > qx.
                // Intersection x * (y2 - y1) = x1*(y2 - y1) + (qy - y1)*(x2 - x1)
                ll den = (y2 - y1); // non-zero
                // left-hand side: x_intersection * den
                // compute lhs = x1 * den + (qy - y1) * (x2 - x1)
                // compare with rhs = qx * den
                // careful with sign of den
                long long lhs = x1 * den + (qy - y1) * (x2 - x1);
                long long rhs = qx * den;
                bool intersectsToRight;
                if (den > 0) intersectsToRight = (lhs > rhs);
                else intersectsToRight = (lhs < rhs);

                if (intersectsToRight) ++intersectCount;
            }
        }

        if (boundary) cout << "BOUNDARY\n";
        else if (intersectCount % 2 == 1) cout << "INSIDE\n";
        else cout << "OUTSIDE\n";
    }

    return 0;
}
