#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int query(int a, vector<int> &b) {
    cout << "1 " << sz(b) << ' ';
    cout << a << ' ';
    for (int &i : b) cout << i << ' ';
    cout << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

pair<vector<int>, vector<int>> split(vector<int> &v) {
    const int n = sz(v);
    vector<int> a(v.begin(), v.begin() + n / 2);
    vector<int> b(v.begin() + n / 2, v.end());
    return {a, b};
}

void solve() {
    int n; cin >> n;
    vector<int> a;
    for (int i = 2; i <= n; i++)
    a.push_back(i);

    int M = query(1, a);
    while (sz(a) > 1) {
        auto [x, y] = split(a);
        int m = query(1, x);
        if (m == M) {
            a = x;
        } else {
            a = y;
        }
    }

    vector<int> b;
    for (int i = 1; i <= n; i++)
    if (i != a[0]) b.push_back(i);
    int ans = query(a[0], b);
    cout << "-1 " << ans << endl;
    cout.flush();
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}