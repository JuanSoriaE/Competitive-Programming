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
    int n, a, smaller = 0, greater = 0;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        int aux; cin >> aux;
        if (aux < a) smaller++;
        else if (aux > a) greater++;
    }

    cout << a + (smaller > greater ? -1 : 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}