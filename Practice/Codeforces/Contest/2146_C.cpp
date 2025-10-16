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

#define  MAX_N 200000

int p[MAX_N];

void solve() {
    int n; string s; cin >> n >> s;
    for (int l = 0; l < n;) {
        if (s[l] == '0') {
            int r = l;
            while (r < n && s[r] == '0') r++;
            r--;
            if (l == r) {
                cout << "NO\n";
                return;
            }

            p[l] = r;
            for (int i = l + 1; i <= r; i++)
                p[i] = i - 1;

            l = r + 1;
        } else {
            p[l] = l;
            l++;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
    cout << (p[i] + 1) << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}