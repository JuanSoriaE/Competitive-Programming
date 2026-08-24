#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100;

int a[MAX_N], b[MAX_N];

void solve() {
    int n, c; cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int op1 = 0;
    for (int i = 0; i < n && op1 != INT_MAX; i++)
    if (a[i] < b[i]) op1 = INT_MAX;
    else op1 += a[i] - b[i];

    sort(a, a + n);
    sort(b, b + n);

    int op2 = c;
    for (int i = 0; i < n; i++)
    if (a[i] < b[i]) {
        cout << "-1\n";
        return;
    } else {
        op2 += a[i] - b[i];
    }

    cout << min(op1, op2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}