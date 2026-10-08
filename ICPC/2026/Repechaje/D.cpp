#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 200000;

bool mex[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, k; cin >> n >> k;
    int extra = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a >= n || mex[a])
            extra++;
        else
            mex[a] = true;
    }

    for (int i = 0; i < n; i++)
    if (!mex[i] && extra && k) {
        mex[i] = true;
        extra--, k--;
    }

    for (int i = 0; i <= n; i++)
    if (!mex[i]) {
        cout << i << '\n';
        return 0;
    }

    return 0;
}