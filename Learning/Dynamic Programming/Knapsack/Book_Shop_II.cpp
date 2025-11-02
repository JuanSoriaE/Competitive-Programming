// https://cses.fi/problemset/task/1159/
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
 
int n, W;
int weight[MAX_N], val[MAX_N];
int qty[MAX_N]; // qty[i] instances of item i
ll dp[MAX_W + 1];
 
vector<pair<int, int>> items;
 
 
// Multiple Knapsack | O(sum(qty[i])W)
ll knapsack() {
    fill(dp, dp + W + 1, 0);
    for (auto &[_w, _v] : items)
    for (int w = W; w >= _w; w--)
        dp[w] = max(dp[w], dp[w - _w] + _v);
    return dp[W];
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> W;
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> qty[i];
 
    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= qty[i]; k <<= 1)
            items.push_back({weight[i] * k, val[i] * k}), qty[i] -= k;
        if (qty[i]) items.push_back({weight[i] * qty[i], val[i] * qty[i]});
    }
 
    cout << knapsack() << '\n';
 
    return 0;
}