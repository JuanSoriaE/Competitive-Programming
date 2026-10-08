#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100000;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<string, string>> v(n);
    for (auto &[a, b] : v) {
        cin >> a;
        b = a;
        sort(all(a));
    }

    sort(all(v));

    int q; cin >> q;
    pair<string, string> p;
    while (q--) {
        cin >> p.first;
        p.second = p.first;
        sort(all(p.first));

        cout << (upper_bound(all(v), p) - v.begin()) << '\n';
    }

    return 0;
}