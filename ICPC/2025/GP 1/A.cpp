#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define lli long long int
#define ld long double
#define uset unordered_set
#define umap unordered_map

bool solve(string &s) {
    string t; cin >> t;
    if (sz(t) % sz(s)) return false;

    for (int i = 0; i < sz(t); i++)
        if (t[i] != s[i % sz(s)]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s; cin >> s;
    int t; cin >> t;
    while (t--) cout << (solve(s) ? "Yes" : "No" ) << "\n";
    return 0;
}