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

#define MAX_N 200000
int a[MAX_N];
int n;

void solve() {
    cin >> n;
    bool even = false, odd = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1) odd = true;
        else even = true;
    }

    if (even && odd) sort(a, a + n);
    for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}