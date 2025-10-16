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

#define MAX_M 200

int a[MAX_M + 1];

int solve() {
    int n, m; cin >> n >> m;
    bool inc = 1; a[0] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        if (a[i] <= a[i - 1]) inc = 0;
    }

    return !inc ? 1 : (n - a[m] + 1);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}