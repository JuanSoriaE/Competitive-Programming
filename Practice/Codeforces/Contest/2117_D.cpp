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

int n;

bool valid(vector<int> &v) {
    int diff = v[1] - v[0];
    if (diff < 0 || diff > v[0]) return 0;

    for (int i = 2; i < n; i++)
    if (v[i] - v[i - 1] != diff) return 0;

    v[0] -= diff;
    return (v[0] % (n + 1) ? 0 : 1);
}

bool solve() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    if (valid(v)) return 1;
    reverse(all(v));
    if (valid(v)) return 1;
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}