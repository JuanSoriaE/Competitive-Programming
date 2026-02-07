#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

#define MAX_N 100000

const double PI2 = 2 * PI;

double angles[2 * MAX_N];

double inline get_angle(const int x, const int y) {
    double angle = atan2(y, x);
    return angle < 0 ? angle + PI2 : angle;
}

void solve() {
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        angles[i] = get_angle(x, y);
    }
    sort(angles, angles + n);

    for (int i = 0; i < n; i++)
        angles[n + i] = angles[i] + PI2;

    double ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, angles[i + k] - angles[i]);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout << fixed << setprecision(8);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}