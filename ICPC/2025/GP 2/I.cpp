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

#define MAX_N 50

ll f[MAX_N];

int solve() {
    ll x, k; cin >> x >> k;
    int l = 0, r = MAX_N - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        ll tmp = f[mid] * x;

        if (tmp == k) return mid + 1;
        if (tmp < k) l = mid + 1;
        else r = mid - 1;
    }

    return l + 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    f[0] = 1; f[1] = 2;
    for (int i = 2; i < MAX_N; i++)
        f[i] = f[i - 1] + f[i - 2];

    int q; cin >> q;
    while (q--) cout << solve() << "\n";
    return 0;
}