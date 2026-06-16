#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

const int MAX_N = 300000;

int a[MAX_N];

void solve() {
    int n; cin >> n >> a[0];
    int real_n = 1;
    for (int i = 1; i < n; i++) {
        int aux; cin >> aux;
        if (a[real_n - 1] != aux)
            a[real_n++] = aux;
    }

    int removed = 0;
    for (int i = 1; i < real_n - 1; i++)
    if ((a[i - 1] < a[i] && a[i] < a[i + 1]) ||
        (a[i - 1] > a[i] && a[i] > a[i + 1]))
        removed++;

    cout << real_n - removed << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}