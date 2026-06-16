#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 3000

int h[MAX_N], w1[MAX_N], w2[MAX_N];
int n;

int mod(int a, int b) {
    return (a % b + b) % b;
}

ll get_ans(int i) {
    w1[i] = w2[i] = 0;
    for (int j = i, cnt = 0; cnt < n - 1; cnt++) {
        int curr = j % n,
            next = (j + 1) % n;

        w1[next] = w1[curr] >= h[curr] ? w1[curr] : h[curr];
        j++;
    }

    for (int j = i, cnt = 0; cnt < n - 1; cnt++) {
        int curr = mod(j, n),
            next = mod(j - 1, n);

        w2[next] = w2[curr] >= h[next] ? w2[curr] : h[next];
        j--;
    }

    ll ans = 0;
    for (int j = 0; j < n; j++)
        ans = ans + min(w1[j], w2[j]);

    return ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];

    for (int i = 0; i < n; i++)
        cout << get_ans(i) << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}