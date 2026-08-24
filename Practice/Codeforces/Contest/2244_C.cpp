#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 200000;

int a[MAX_N + 1];
int p[MAX_N + 1], _size[MAX_N + 1];

int find(int a) { return a == p[a] ? a : p[a] = find(p[p[a]]); }
void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;

    if (_size[a] > _size[b]) swap(a, b);
    p[a] = b;
    _size[b] += _size[a];
}

void reset(const int &n) {
    iota(p + 1, p + n + 1, 1);
    fill(_size + 1, _size + n + 1, 1);
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    reset(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i - x > 0) unite(a[i], a[i - x]);
        if (i - y > 0) unite(a[i], a[i - y]);
    }

    for (int i = 1; i <= n; i++)
    if (find(i) != find(a[i])) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}