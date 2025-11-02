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
    string s, t; cin >> s >> t;
    map<char, int> cnt;
    for (char &c : s) cnt[c]++;

    for (char &c : t)
    if (!cnt.count(c)) return false;
    else cnt[c]--;

    for (auto &[c, i] : cnt)
    if (i != 0) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << (solve() ? "YES" : "NO") << '\n';
    return 0;
}