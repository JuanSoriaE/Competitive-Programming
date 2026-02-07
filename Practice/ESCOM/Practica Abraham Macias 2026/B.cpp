#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define uset unordered_set
#define umap unordered_map

#define MAX_N 200000

int prefix[MAX_N + 1];

int query(int l, int r) {
    cout << "? " << (r - l + 1) << ' ';
    for (int i = l; i <= r; i++)
        cout << i << " ";
    cout << '\n';
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    int l = 1, r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        int res = query(l, m),
            real = prefix[m] - prefix[l - 1];

        if (res == real) l = m + 1;
        else r = m;
    }

    cout << "! " << l << '\n';
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    prefix[0] = 0;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}