#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    map<int, int> freqs;
    freqs[0] = 0;
    for (auto &[k, v] : cnt)
        freqs[v]++;

    int cur_n = n, diff = cnt.size();
    int prev_freq = 0, ans = 0;
    for (auto it = freqs.begin(); it != prev(freqs.end()); it++) {
        auto [freq, freq_diff] = *it;
        cur_n -= (freq - prev_freq) * diff;
        diff -= freq_diff;

        if (cur_n == k) ans++;
        else if (cur_n < k) {
            if ((k - cur_n) % diff == 0) ans++;
        } else {
            int min_nxt = cur_n - (next(it)->first - freq) * (diff);
            if (k > min_nxt && (cur_n - k) % diff == 0)
                ans++;
        }

        prev_freq = freq;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}