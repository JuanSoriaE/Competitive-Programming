#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m, o; cin >> n >> m >> o;
    vector<int> q(n);
    for (int &i : q) cin >> i;

    vector<vector<pair<int, int>>> dishes(m);
    for (int i = 0; i < m; i++) {
        int d; cin >> d;
        dishes[i].resize(d);
        for (auto &[a, b] : dishes[i]) cin >> a >> b;
    }

    for (int i = 0; i < o; i++) {
        int x; cin >> x;
        while (x--) {
            int d; cin >> d;
            for (auto &[ing, qty] : dishes[d - 1]) {
                q[ing - 1] -= qty;
                if (q[ing - 1] < 0) {
                    cout << i << '\n';
                    return 0;
                }
            }
        }
    }

    cout << o << '\n';

    return 0;
}