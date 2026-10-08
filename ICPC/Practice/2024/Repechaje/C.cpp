#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 1000;
constexpr int MAX_W = 780;

int b[MAX_N], p[MAX_N], f[MAX_N];

int n;
ll dp[MAX_W + 1];

ll kanpsack(int *val) {
    fill(dp, dp + MAX_W + 1, 0);
    for (int i = 0; i < n; i++)
    for (int w = MAX_W; w >= b[i]; w--)
    if (w - b[i] < 480)
        dp[w] = max(dp[w], dp[w - b[i]] + val[i]);

    ll res = 0;
    for (int i = 0; i <= MAX_W; i++)
        res = max(res, dp[i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] *= 3;
    }
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> f[i];

    int a = kanpsack(p), b = kanpsack(f);
    if (a == b) cout << "EITHER\n";
    else if (a > b) cout << "PLEASURE\n";
    else cout << "FAME\n";

    return 0;
}