#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    long long x;
    long long y;
    Point(long long x_ = 0, long long y_ = 0) : x(x_), y(y_) {}

    // cross product: this x q = this->x * q.y - this->y * q.x
    long long operator-(const Point &q) const {
        return x * q.y - y * q.x;
    }
};

void solve(const vector<Point> &arr) {
    int n = (int)arr.size();
    long long sum = 0; // will contain 2 * signed area
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        sum += (arr[i] - arr[j]); // uses operator-
    }

    long long area2 = llabs(sum); // absolute value of 2 * area

   cout<<area2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    if (n < 1) return 0;

    vector<Point> arr;
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        long long xi, yi;
        cin >> xi >> yi;
        arr.emplace_back(xi, yi);
    }

    if (n < 3) {
      
        return 0;
    }

    solve(arr);
    return 0;
}
