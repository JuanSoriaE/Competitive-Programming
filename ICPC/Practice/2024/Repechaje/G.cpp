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
constexpr int MAX_A = 10000000;

int a[MAX_N];

int spf[MAX_A + 1];
void compute_spf() {
    iota(spf, spf + MAX_A + 1, 0);
    for (int i = 2; i * i <= MAX_A; i++)
    if (spf[i] == i)
        for (int j = i * i; j <= MAX_A; j += i)
        if (spf[j] == j) spf[j] = i;
}

set<int> st;
bool factors_in_set(int n) {
    while (n > 1) {
        int p = spf[n];
        if (st.count(p)) return true;
        st.insert(p);
        while (n % p == 0) n /= p;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    compute_spf();
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int gcd = __gcd(a[0], a[1]);
    for (int i = 0; i < n; i++) {
        if (a[i] % gcd || factors_in_set(a[i] / gcd)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}