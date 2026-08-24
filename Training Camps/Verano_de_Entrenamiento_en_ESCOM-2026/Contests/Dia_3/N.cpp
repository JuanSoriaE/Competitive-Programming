#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr ld E = 1e-9;

bool valid(ld t, vector<int> &x, vector<int> &v) {
    vector<ld> starts(sz(x));
    vector<ld> ends(sz(x));
    for (int i = 0; i < sz(x); i++) {
        starts[i] = x[i] - v[i] * t;
        ends[i] = x[i] + v[i] * t;
    }

    sort(all(starts));
    sort(all(ends));

    int s = 0, e = 0, cur = 0, max_cur = 0;
    while (s < sz(starts)) {
        if (starts[s] <= ends[e])
            cur++, s++;
        else
            cur--, e++;
        max_cur = max(max_cur, cur);
    }
    return max_cur == sz(x);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<int> x(n);
    for (int &i : x) cin >> i;
    vector<int> v(n);
    for (int &i : v) cin >> i;

    ld l = 0, r = 1e9, ans;
    while (r - l > E) {
        ld m = (l + r) / 2;
        if (valid(m, x, v))
            ans = m, r = m;
        else
            l = m;
    }
    cout << setprecision(25) << ans << '\n';

    return 0;
}