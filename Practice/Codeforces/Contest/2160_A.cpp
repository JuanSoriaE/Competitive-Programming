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

#define MAX_A 100
bool vst[MAX_A + 2];

void solve() {
    for (int i = 0; i < MAX_A + 2; i++) vst[i] = 0;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        vst[a] = 1;
    }

    for (int i = 0; i < MAX_A + 2; i++)
    if (!vst[i]) {
        cout << i << '\n';
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}