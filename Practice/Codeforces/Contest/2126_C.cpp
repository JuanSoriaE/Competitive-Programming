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

bool solve() {
    int n, k; cin >> n >> k;
    set<int> st;
    int cur;
    for (int i = 0; i < n; i++) {
        int aux; cin >> aux;
        st.insert(aux);

        k--;
        if (!k) cur = aux;
    }

    int water = 1;
    for (const int h : st) {
        if (h <= cur) continue;
        water += h - cur;
        if (water - 1 > cur) return 0;
        cur = h;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}