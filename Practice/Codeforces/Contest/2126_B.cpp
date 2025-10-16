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
    int n, k; cin >> n >> k;
    int aux, ans = 0;
    bool able = 1;
    for (int i = 0, cnt = 0; i < n; i++) {
        cin >> aux;
        if (aux || !able) {
            cnt = 0; able = 1;
            continue;
        }

        cnt++;
        if (cnt == k) {
            ans++;
            cnt = 0;
            able = 0;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}