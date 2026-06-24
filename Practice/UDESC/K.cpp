#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 300000

int a[MAX_N];
int ans[MAX_N + 1];

void increment_divs(int &n, int inc) {
    for (int i = 1; i * i <= n; i++)
    if (n % i == 0) {
        ans[i] += inc;
        if (n / i != i)
            ans[n / i] += inc;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    for (auto &[k, v] : freq)
        increment_divs(v, 1);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, y; cin >> i >> y; i--;
            increment_divs(freq[a[i]], -1);
            freq[a[i]]--;
            increment_divs(freq[a[i]], 1);

            increment_divs(freq[y], -1);
            freq[y]++;
            increment_divs(freq[y], 1);

            a[i] = y;
        } else {
            int x; cin >> x;
            cout << (x > MAX_N ? 0 : ans[x]) << '\n';
        }
    }

    return 0;
}