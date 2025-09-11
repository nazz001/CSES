#include <bits/stdc++.h>
using namespace std;

// Use a simple POD-like struct with a default ctor (needed for vector<Point>(4))
struct Point {
    long long x;
    long long y;
    Point() : x(0), y(0) {}
    Point(long long x_, long long y_) : x(x_), y(y_) {}
};

// Cross product of vectors (a->b) x (a->c)
long long cross(const Point &a, const Point &b, const Point &c) {
    // (b - a) x (c - a) = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x)
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Orientation: returns 0 if collinear, 1 if clockwise (cross < 0), 2 if counterclockwise (cross > 0)
// (You can also just use the raw cross value, but this matches many textbook implementations)
int orient(const Point &p, const Point &q, const Point &r) {
    long long val = cross(p, q, r);
    if (val == 0) return 0;
    return (val > 0) ? 2 : 1;
}

// Check if point r lies on segment pq (assumes integer coordinates).
bool onSegment(const Point &p, const Point &q, const Point &r) {
    // r must be within bounding box of p and q
    return (r.x <= max(p.x, q.x) && r.x >= min(p.x, q.x) &&
            r.y <= max(p.y, q.y) && r.y >= min(p.y, q.y));
}

bool segmentsIntersect(const Point &p, const Point &q, const Point &r, const Point &s) {
    int o1 = orient(p, q, r);
    int o2 = orient(p, q, s);
    int o3 = orient(r, s, p);
    int o4 = orient(r, s, q);

    // General case
    if (o1 != o2 && o3 != o4) return true;

    // Special Cases: check collinear + onSegment
    if (o1 == 0 && onSegment(p, q, r)) return true;
    if (o2 == 0 && onSegment(p, q, s)) return true;
    if (o3 == 0 && onSegment(r, s, p)) return true;
    if (o4 == 0 && onSegment(r, s, q)) return true;

    return false;
}

void solve(const vector<Point> &data) {
    // data[0..3] = p, q, r, s
    const Point &p = data[0];
    const Point &q = data[1];
    const Point &r = data[2];
    const Point &s = data[3];

    if (segmentsIntersect(p, q, r, s))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        vector<Point> data(4);
        for (int i = 0; i < 4; ++i) {
            cin >> data[i].x >> data[i].y;
        }
        solve(data);
    }
    return 0;
}
