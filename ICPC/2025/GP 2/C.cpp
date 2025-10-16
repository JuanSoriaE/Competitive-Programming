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

#define MOD 998244353

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> mp(100001, -1); mp[a[n - 1]] = n - 1;
    vector<ll> dp(n, 0); dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = (dp[i + 1] + (mp[a[i]] != -1 ? dp[mp[a[i]]] : 0)) % MOD;
        mp[a[i]] = i;
    }
    
    cout << dp[0] << "\n";
    return 0;
}