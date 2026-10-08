#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

struct Point {
    ld x, y;
    int i;

    bool operator<(const Point &o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};

ld cross(Point &o, Point &p, Point &q) {
    return (p.x - o.x) * (q.y - o.y) - (p.y - o.y) * (q.x - o.x);
}
vector<Point> convex_hull(vector<Point> &points) {
    sort(all(points));
    const int n = sz(points);
    if (n < 3) return points;

    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        while (sz(hull) > 1 &&
            cross(hull[sz(hull) - 2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    auto lower_hull_len = sz(hull);
    for (int i = n - 2; i >= 0; i--) {
        while (sz(hull) > lower_hull_len &&
            cross(hull[sz(hull) - 2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back();
    return hull;
}

void solve() {
    int n; cin >> n;
    vector<Point> points(n);
    cin >> points[0].x >> points[0].y;

    ld min_d = 1e10, max_d = 0;
    for (int j = 1; j < n; j++) {
        auto &[x, y, i] = points[j];
        cin >> x >> y; i = j;
        x -= points[0].x;
        y -= points[0].y;
        ld d = sqrt(x * x + y * y);
        min_d = min(min_d, d); max_d = max(max_d, d);
    }
    points[0] = {0, 0, 0};

    ld R2 = min_d * max_d;
    for (int j = 1; j < n; j++) {
        auto &[x, y, i] = points[j];
        ld tmp = x;
        x *= R2 / (x * x + y * y);
        y *= R2 / (tmp * tmp + y * y);
    }

    vector<Point> convex = convex_hull(points);
    sort(all(convex), [](const Point &a, const Point &b) {
        return a.i < b.i;
    });

    bool p0_in_convex = !convex.empty() && convex[0].i == 0;
    cout << sz(convex) - p0_in_convex << ' ';
    for (int i = p0_in_convex; i < sz(convex); i++)
        cout << convex[i].i << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}