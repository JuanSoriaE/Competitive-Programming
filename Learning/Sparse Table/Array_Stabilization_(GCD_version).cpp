// https://codeforces.com/problemset/problem/1547/F
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
constexpr int K = 20;

int n;
int a[MAX_N];
int st[K + 1][MAX_N];

int f(int a, int b) { return __gcd(a, b); }
void build_st() {
    copy(a, a + n, st[0]);
    for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= n; j++)
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
int log2_floor(int n) { return 31 - __builtin_clz(n); }
int query(int l, int r) {
    int i = log2_floor(r - l + 1);
    return f(st[i][l], st[i][r - (1 << i) + 1]);
}

int get_min_steps(int i, int target) {
    int l = 0, r = n - 1;
    int min_steps;

    while (l <= r) {
        int m = l + (r - l) / 2;

        int end = (i + m) % n;
        int res = end < i ? query(0, end) : a[i];
        end = end < i ? n - 1 : end;
        res = f(res, query(i, end));

        if (res > target) l = m + 1;
        else min_steps = m, r = m - 1;
    }

    return min_steps;
}

void solve() {
    cin >> n;
    int target = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (target == -1) target = a[i];
        else target = f(target, a[i]);
    }

    build_st();

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, get_min_steps(i, target));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}