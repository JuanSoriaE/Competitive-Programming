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

#define MAX_N 200000
#define MAX_A 200001
int a[MAX_N + 1];

// Smallest prime of every number from 1 to MAX_A | O(nlog(log(n))) | Limit 10^7
int spf[MAX_A + 1];
void compute_spf() {
    iota(spf, spf + MAX_A + 1, 0);
    for (int i = 2; i * i <= MAX_A; i++)
    if (spf[i] == i)
        for (int j = i * i; j <= MAX_A; j += i)
        if (spf[j] == j) spf[j] = i;
}

// Factorization of number | O(log(n)) if n is prime
vector<int> factors(int n) {
    vector<int> factors;
    while (n > 1) {
        int p = spf[n];
        while (n % p == 0) n /= p;
        factors.push_back(p);
    }
    return factors;
}

int solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> a[n];

    set<int> seen;
    for (int i = 0; i < n; i++)
    for (int &f : factors(a[i]))
        if (seen.count(f)) return 0;
        else seen.insert(f);

    for (int i = 0; i < n; i++)
    for (int &f : factors(a[i] + 1))
        if (seen.count(f)) return 1;

    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    compute_spf();
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
    return 0;
}