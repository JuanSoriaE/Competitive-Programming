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

struct Casino {
    int l, r;
    int real;

    bool operator<(const Casino &other) const {
        return real < other.real;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<Casino> casinos(n);
    for (int i = 0; i < n; i++) {
        cin >> casinos[i].l;
        cin >> casinos[i].r;
        cin >> casinos[i].real;
    }

    sort(all(casinos));

    for (int i = 0; i < n; i++) {
        if (casinos[i].real <= k || casinos[i].l > k || casinos[i].r < k) continue;
        k = casinos[i].real;
    }

    cout << k << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}