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

int a[MAX_N];
int n;

int spf[MAX_N + 1];
void compute_spf() {
    iota(spf, spf + n + 1, 0);
    for  (int i = 2; i * i <= n; i++)
    if (spf[i] == i)
        for (int j = i * i; j <= n; j+= i)
        if (spf[j] == j) spf[j] = i;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> n >> q;
    compute_spf();
    iota(a, a + n, 1);

    sort(a, a + n, [&](int a, int b) {
        while (spf[a] == spf[b]) {
            a /= spf[a]; b /= spf[b];
        }
        return spf[a] < spf[b];
    });

    while (q--) {
        int k; cin >> k;
        cout << a[k - 1] << '\n';
    }

    return 0;
}