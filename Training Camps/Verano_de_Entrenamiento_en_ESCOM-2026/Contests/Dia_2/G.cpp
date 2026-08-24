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

int p[MAX_N], ans[MAX_N];

int find(int i) {
    if (i == p[i]) return i;
    int par = find(p[i]);
    ans[i] = min(ans[i], ans[p[i]]);
    return p[i] = par;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    iota(p, p + n, 0);
    for (int i = 0; i < n; i++)
        cin >> ans[i];

    while (m--) {
        char op; cin >> op;
        if (op == '+') {
            int i, j; cin >> i >> j;
            i--, j--;
            p[j] = i;
            find(j);
        } else {
            int i; cin >> i;
            i--;
            find(i);
            cout << ans[i] << '\n';
        }
    }
    return 0;
}