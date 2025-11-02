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
ll dp[MAX_W + 1];

// 0-1 Knapsack | O(nW)
ll knapsack() {
    fill(dp, dp + W + 1, 0);
    for (int i = 0; i < n; i++)
    for (int w = W; w >= weight[i]; w--)
        dp[w] = max(dp[w], dp[w - weight[i]] + val[i]);
    return dp[W];
}

// Complete Knapsack (Unlimited amount of each item) | O(nW)
ll knapsack() {
    fill(dp, dp + W + 1, 0);
    for (int i = 0; i < n; i++)
    for (int w = weight[i]; w <= W; w++)
        dp[w] = max(dp[w], dp[w - weight[i]] + val[i]);
    return dp[W];
}

int qty[MAX_N]; // k[i] instances of item i

// Multiple Knapsack | O(sum(k[i])W)
ll knapsack() {
    fill(dp, dp + W + 1, 0);
    for (int i = 0; i < n; i++)
    for (int w = W; w >= weight[i]; w--)
    for (int k = 0; k <= qty[i] && k * weight[i] <= w; k++)
        dp[w] = max(dp[w], dp[w - k * weight[i]] + k * val[i]);
    return dp[W];
}

pair<int, int> items[MAX_N];

// Multiple Knapsack (Binary Grouping) | O(sum(log(k[i]))W)
ll knapsack() {
    int items_i = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= qty[i]; k <<= 1) {
            items[items_i++] = {weight[i] * k, val[i] * k};
            qty[i] -= k;
        }
        if (qty[i])
            items[items_i++] = {weight[i] * qty[i], val[i] * qty[i]};
    }

    fill(dp, dp + W + 1, 0);
    for (auto &[wei, v] : items)
    for (int w = W; w >= wei; w--)
        dp[w] = max(dp[w], dp[w - wei] + v);
    return dp[W];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}