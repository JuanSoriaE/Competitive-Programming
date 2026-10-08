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

bool v[MAX_N + 1], d[MAX_N + 1];

int p[MAX_N + 1], _size[MAX_N + 1];
bool parity[MAX_N + 1];

int find(int a) { return a == p[a] ? a : p[a] = find(p[p[a]]); }
void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;

    if (_size[a] > _size[b]) swap(a, b);
    p[a] = b;
    _size[b] += _size[a];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];

    d[0] = v[0];
    for (int i = 1; i <= n; i++)
        d[i] = v[i] != v[i - 1];

    iota(p, p + n + 1, 0); fill(_size, _size + n + 1, 1);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        unite(l, r + 1);
    }

    for (int i = 0; i <= n; i++)
    if (d[i]) parity[find(i)] ^= 1;

    for (int i = 0; i <= n; i++)
    if (parity[find(i)]) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    return 0;
}