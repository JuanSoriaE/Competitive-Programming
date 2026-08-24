#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int query(vector<int> &a, vector<int> &b) {
    cout << sz(a) << ' ' << sz(b) << ' ';
    for (int &i : a) cout << i << ' ';
    for (int &i : b) cout << i << ' ';
    cout << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;

    int ans = 0;
    for (int i = 0; (1 << i) <= n; i++) {
        vector<int> a, b;
        for (int j = 1; j <= n; j++)
        if (j & (1 << i)) a.push_back(j);
        else b.push_back(j);

        ans = max(ans, query(a, b));
    }
    cout << "-1 " << ans << '\n';
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}