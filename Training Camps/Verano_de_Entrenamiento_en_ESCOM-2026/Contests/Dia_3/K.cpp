#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100;

int p[MAX_N], _size[MAX_N];
int sets;

int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (_size[a] > _size[b]) swap(a, b);
    p[a] = b;
    _size[b] += _size[a];
    sets--;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    iota(p, p + n, 0);
    fill(_size, _size + n, 1);
    sets = n;
    vector<vector<int>> X(1001), Y(1001);

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        X[x].push_back(i);
        Y[y].push_back(i);
    }

    for (int x = 1; x <= 1000; x++) {
        for (int i = 0; i < sz(X[x]) - 1; i++)
            unite(X[x][i], X[x][i + 1]);
    }
    for (int y = 1; y <= 1000; y++) {
        for (int i = 0; i < sz(Y[y]) - 1; i++)
            unite(Y[y][i], Y[y][i + 1]);
    }

    cout << sets - 1 << '\n';

    return 0;
}