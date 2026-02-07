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

int n;
int a[MAX_N], dp[MAX_N];

// O(n^2) Solution
int lis() {
    fill(dp, dp + n, 1);
    for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
    if (a[j] < a[i])
        dp[i] = max(dp[i], dp[j] + 1);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    return ans;
}

int dp[MAX_N + 1];

// LIS | O(nlog(n))
int lis() {
    fill(dp, dp + n + 1, INT_MAX);
    dp[0] = INT_MIN;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(dp, dp + n + 1, a[i]) - dp;
        if (dp[l - 1] < a[i] && a[i] < dp[l])
            dp[l] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (dp[i] < INT_MAX) ans = i;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}