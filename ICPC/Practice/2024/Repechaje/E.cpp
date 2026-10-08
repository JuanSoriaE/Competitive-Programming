#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100000;
constexpr int MOD = 1000000007;

int n;
vector<pair<int, ll>> adj[MAX_N];
ll d[MAX_N];

ll fact[MAX_N], inv_fact[MAX_N];

ll bin_pow(ll a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void compute_facts() {
    fact[0] = fact[1] = 1LL;
    for (ll i = 2; i < MAX_N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    inv_fact[MAX_N - 1] = bin_pow(fact[MAX_N - 1], MOD - 2);
    for (ll i = MAX_N - 2; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1LL)) % MOD;
}

ll C(int n, int k) {
    if (k > n) return 0;
    return ((fact[n] * inv_fact[k]) % MOD * inv_fact[n - k]) % MOD;
}

void compute_shortest_path() {
    fill(d, d + n, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    d[0] = 0LL;
    pq.push({0LL, 0});

    while (!pq.empty()) {
        auto [cur_d, u] = pq.top(); pq.pop();
        if (cur_d > d[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (cur_d + w >= d[v]) continue;
            d[v] = cur_d + w;
            pq.push({cur_d + w, v});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    compute_facts();

    int m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    compute_shortest_path();
    sort(d + 1, d + n);

    ll ans = 0, inv_total = bin_pow(C(n - 1, k), MOD - 2);
    for (int i = 1; i <= n - k; i++) {
        ll p = (C(n - i - 1, k - 1) * inv_total) % MOD;
        ans = (ans + (p * d[i]) % MOD) % MOD;
    }

    cout << ans << '\n';

    return 0;
}