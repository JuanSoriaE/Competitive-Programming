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

int query(int type, int l, int r) {
    cout << type << ' ' << l << ' ' << r << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n; cin >> n;
    int og = query(1, 1, n), mod = query(2, 1, n),
        win_size = mod - og;

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;

        og = query(1, l, mid);
        mod = query(2, l, mid);
        if (og != mod) r = mid;
        else l = mid + 1;
    }

    cout << "! " << l << ' ' << (l + win_size - 1) << endl;
    cout.flush();
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}