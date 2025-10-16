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

int solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;

    int l = 0, ans = 0;
    while (l < n) {
        ans++;
        int r = l + 1;
        while (r < n && v[r] - v[l] <= 1) r++;
        l = r;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}