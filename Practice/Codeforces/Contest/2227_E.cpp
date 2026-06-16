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

int a[MAX_N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll total = 0; int add = 0;
    pair<int, int> mini = {a[n - 1], n - 1};
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < mini.first) {
            add = max(add, mini.second - i - 1);
            mini = {a[i], i};
        }
        total += a[i] - mini.first;
    }
    add = max(add, mini.second);

    cout << total + add << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}