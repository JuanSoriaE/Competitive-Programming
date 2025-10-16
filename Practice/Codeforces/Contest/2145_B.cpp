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

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (n == k) {
        for (int i = 0; i < n; i++) cout << '-';
        cout << '\n';
        return;
    }

    int a, b, c; a = b = c = 0;
    for (char &ch : s) {
        if (ch == '0') a++;
        else if (ch == '1') b++;
        else c++;
    }

    int rem = n - a - b;
    for (int i = 0; i < a; i++) cout << '-';
    for (int i = 0; i < min(c, rem - c); i++) cout << '?';
    for (int i = 0; i < (rem - 2 * c); i++) cout << '+';
    for (int i = 0; i < c; i++) cout << '?';
    for (int i = 0; i < b; i++) cout << '-';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}