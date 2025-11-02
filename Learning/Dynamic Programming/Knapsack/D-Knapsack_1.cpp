// https://atcoder.jp/contests/dp/tasks/dp_d
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

#define MAX_N 100
#define MAX_W 100000
int weight[MAX_N], val[MAX_N];
ll dp[MAX_W + 1];

int n, W;

ll knapsack() {
    dp[W] = 0;
    for (int i = 0; i < n; i++)
    for (int w = W; w >= weight[i]; w--)
        dp[w] = max(dp[w], dp[w - weight[i]] + val[i]);
    return dp[W];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> W;
    for (int i = 0; i < n; i++) cin >> weight[i] >> val[i];

    cout << knapsack() << '\n';

    return 0;
}