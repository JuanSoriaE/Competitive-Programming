#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define uset unordered_set
#define umap unordered_map

#define MAX_N 100
#define MAX_A 1000
int a[MAX_N], b[MAX_N];
int cnt[MAX_A + 1] = {0};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        cnt[b[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    if (a[i] == b[i]) {
        if (cnt[a[i]] <= 1) ans++;
    } else {
        if (cnt[a[i]] == 0) ans++;
    }

    cout << ans << '\n';

    return 0;
}