#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 100000

bool vst[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        vst[a] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    if (!vst[i]) ans++;
    cout << ans << '\n';

    return 0;
}