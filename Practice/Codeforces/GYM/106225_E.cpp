#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 200000

int prefix_8[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for (int i = 1; i <= n; i++)
        prefix_8[i] = prefix_8[i - 1] + static_cast<int>(s[i - 1] == '8');

    while (q--) {
        int l, r, x, y; cin >> l >> r >> x >> y;
        x = abs(x); y = abs(y);
        if (x < y) swap(x, y);

        int len = r - l + 1;
        int cnt_8 = prefix_8[r] - prefix_8[l - 1];

        if (y > len) {
            cout << "NO\n";
            continue;
        }

        int max_d = min(y + len, cnt_8 + len);
        cout << (x + y <= max_d ? "YES" : "NO") << '\n';
    }

    return 0;
}