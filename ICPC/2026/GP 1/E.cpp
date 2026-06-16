#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 1000000

vector<int> a[MAX_N + 1];
int n;

int spf[MAX_N + 1];
void compute_spf() {
    iota(spf, spf + n + 1, 0);
    for  (int i = 2; i * i <= n; i++)
    if (spf[i] == i)
        for (int j = i * i; j <= n; j+= i)
        if (spf[j] == j) spf[j] = i;
}

vector<int> factors(int n) {
    vector<int> factors;
    while (n > 1) {
        int p = spf[n];
        factors.push_back(p);
        n /= p;
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> n >> q;
    compute_spf();

    for (int i = 1; i <= n; i++)
        a[i] = factors(i);
    sort(a + 1, a + 1 + n);

    while (q--) {
        int k; cin >> k;
        int ans = 1;
        for (int &i : a[k]) ans *= i;
        cout << ans << '\n';
    }

    return 0;
}