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

#define MAX_N 100000
int a[MAX_N];

int n;

deque<pair<int, int>> q;
int cnt_added = 0, cnt_removed = 0;
int get_min() { return q.front().first; }
void add(int x) {
    while (!q.empty() && q.back().first > x)
        q.pop_back();
    q.push_back({x, cnt_added++});
}
void remove() {
    if (!q.empty() && q.front().second == cnt_removed)
        q.pop_back();
    cnt_removed++;
}

int expected;

ll solve() {
    q.clear();
    int prefix = 0;
    for (int i = 0; i < n; i++) {
        prefix += (a[i] - expected);
        add(prefix);
    }

    int start = -1, add = 0;
    for (int i = 0; i < n; i++) {
        if (get_min() + add >= 0) {
            start = i;
            break;
        }

        remove();
        add -= (a[i] - expected);
    }

    ll res = 0;
    int cur = 0;
    for (int i = start, cnt = 0; cnt < n; i = (i + 1) % n, cnt++) {
        res += cur;
        cur += a[i] - expected;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    expected = sum / n;

    ll x = solve();
    reverse(a, a + n);
    ll y = solve();
    cout << min(x, y) << '\n';

    return 0;
}