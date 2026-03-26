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

#define MAX_N 100

int a[MAX_N];

bool solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    for (int i = 1; i < n - 1; i += 2)
    if (a[i] != a[i + 1]) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << (solve() ? "YES" : "NO") << '\n';
    return 0;
}