#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

vector<int> primes;
void compute_primes(int n) {
    vector<bool> seen(n + 1);
    primes.push_back(2);
    for (int i = 4; i <= n; i += 2) seen[i] = true;
    for (int i = 3; i <= n; i++) {
        if (!seen[i]) {
            primes.push_back(i);
            for (ll j = (ll)i * i; j <= n; j += 2 * i)
                seen[j] = true;
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << 1 << ' ';
    for (int i = 1; i < n; i++)
        cout << static_cast<ll>(primes[i]) * primes[i - 1] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    compute_primes(104729);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}