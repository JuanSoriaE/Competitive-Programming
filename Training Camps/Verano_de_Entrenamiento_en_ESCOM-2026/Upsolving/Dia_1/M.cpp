#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 2000;

int v[MAX_N];

vector<int> divisors(const int &n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
        res.push_back(i), res.push_back(n / i);
    res.push_back(n);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> divs = divisors(n);
    int ans = INT_MAX;
    for (int &k : divs) {
        vector<int> rem(k);
        for (int i = 0; i < n; i++)
            rem[v[i] % k]++;
        bool valid = true;
        for (int i = 0; i < k; i++)
        if (rem[i] != n / k) valid = false;

        if (valid)
            ans = min(ans, k);
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';

    return 0;
}