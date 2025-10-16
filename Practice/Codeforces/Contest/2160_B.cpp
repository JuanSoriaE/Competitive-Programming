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

#define MAX_N 100000
int a[MAX_N];
ll b[MAX_N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];

    int cur = a[0] = 1;
    for (int i = 1; i < n; i++)
    if (b[i - 1] + i + 1 == b[i]) cur++, a[i] = cur;
    else a[i] = a[i - (b[i] - b[i - 1])];

    for (int i = 0; i < n; i++) cout << a[i]  << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}