#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100000;

int pref_c[MAX_N + 1], pref_v[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, v; cin >> c >> v;
        pref_c[i] = pref_c[i - 1] + c;
        pref_v[i] = pref_v[i - 1] + v;
    }

    int q; cin >> q;
    while (q--) {
        int i; cin >> i;
        int c = pref_c[i], v = pref_v[i];

        if (c == v) cout << "NEUTRO\n";
        else if (c > v) cout << "COMPRA\n";
        else cout << "VENDA\n";
    }

    return 0;
}