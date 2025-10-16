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

bool solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> seen(26, -1);
    for (int i = 0; i < n - 1; i++) {
        if (seen[s[i] - 'a'] > -1) return 1;
        seen[s[i] - 'a'] = i;
    }
    return seen[s[n - 1] - 'a'] > 0;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << (solve() ? "Yes" : "No") << "\n";
    return 0;
}