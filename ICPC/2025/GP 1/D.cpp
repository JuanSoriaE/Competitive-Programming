#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define lli long long int
#define ld long double
#define uset unordered_set
#define umap unordered_map

void solve() {
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int k; cin >> k;
    vector<ll> ing(k);
    for (int i = 0; i < k; i++)
        cin >> ing[i];
    
    int n; cin >> n;
    vector<vector<ll>> orders(n, vector<ll>(k)), prefix_sum(n, vector<ll>(k));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++) {
        cin >> orders[i][j];
        prefix_sum[i][j] = orders[i][j] + (i == 0 ? 0 : prefix_sum[i - 1][j]);
    }

    ll day = LLONG_MAX;
    for (int i = 0; i < k; i++)
    if (prefix_sum[n - 1][i])
        day = min(day, ing[i] / prefix_sum[n - 1][i] + 1);

    for (int i = 0; i < k; i++)
        ing[i] -= (day - 1) * prefix_sum[n - 1][i];

    ll order = -1;
    for (int i = 0; i < n && order == -1; i++)
    for (int j = 0; j < k && order == -1; j++) {
        ing[j] -= orders[i][j];
        if (ing[j] < 0)
            order = i + 1;
    }

    cout << day << " "<< order << "\n";

    return 0;
}