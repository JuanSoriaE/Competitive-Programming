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

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    bool is_B = false;
    vector<pair<char, int>> ops;
    for (char &c : s) {
        if (c == 'B') is_B = true;

        if (!ops.empty() && ops.back().first == c)
            ops.back().second++;
        else
            ops.push_back({c, 1});
    }

    while (q--) {
        int a; cin >> a;
        if (!is_B) {
            cout << a << '\n';
            continue;
        }

        int i = 0, ans = 0;
        while (a) {
            if (ops[i].first == 'A') {
                int new_a = max(a - ops[i].second, 0);
                ans += a - new_a;
                a = new_a;
            } else {
                for (int j = 0; a && j < ops[i].second; j++)
                    ans++, a >>= 1;
            }
            i = (i + 1) % sz(ops);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}