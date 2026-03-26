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
#define ii pair<int, int>

#define MAX_N 200000

int a[2][MAX_N];
int n;

bool is_valid(set<int> *blocker) {
    if (blocker[0].count(0) ||
        blocker[1].count(n - 1)) return false;

    if (blocker[0].empty() || blocker[1].empty()) return true;

    return *blocker[0].begin() > *blocker[1].rbegin() + 1;
}

void add(int r, vector<ii> *pos, set<int> *blocker) {
    for (auto &[x, y] : pos[r])
        blocker[x].erase(y);
}
void remove(int l, vector<ii> *pos, set<int> *blocker) {
    for (auto &[x, y] : pos[l])
        blocker[x].insert(y);
}

void solve() {
    cin >> n;

    vector<ii> pos[2 * n + 1];
    set<int> blocker[2];
    for (int i = 0; i < n; i++)
        blocker[0].insert(i), blocker[1].insert(i);

    for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        pos[a[i][j]].push_back({i, j});
    }

    ll ans = 0;
    int r = 1;
    add(r, pos, blocker);

    for (int l = 1; l <= 2 * n; l++) {
        while (r < 2 * n && !is_valid(blocker))
            add(++r, pos, blocker);
        if (!is_valid(blocker)) break;

        ans += 2 * n - r + 1;
        remove(l, pos, blocker);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}