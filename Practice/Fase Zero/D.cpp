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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int a1 = 0, a2 = 0;
    for (char &c : s)
    if (c == '*') a1++;

    for (char &c : t)
    if (c == '*') a2++;

    ld a3 = (ld)a2 / a1;
    ld ans = 1 - a3;
    debug(ans);
    return 0;
}