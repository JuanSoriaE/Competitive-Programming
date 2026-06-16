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

int n;
int a[MAX_N];
ll pref[MAX_N], suff[MAX_N + 1];

void reset() {
    fill(pref, pref + n, 0);
    fill(suff, suff + n + 1, 0);
}

void solve() {
    int k; cin >> n >> k;
    reset();
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    sort(a, a + n);

    pref[0] = a[0]; suff[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i],
        suff[n - 1 - i] = suff[n - i] + a[n - 1 - i];

    ll mini = suff[n - k];
    for (int op1 = 1; op1 <= k; op1++) {
        int op2 = k - op1;
        mini = min(mini, pref[2 * op1 - 1] + suff[n - op2]);
    }

    cout << total - mini << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}