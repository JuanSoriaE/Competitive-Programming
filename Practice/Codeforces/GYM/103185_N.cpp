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

int read() {
    int x;
    string s; cin >> s;
    x = atoi(s.substr(1, sz(s) - 4).c_str()) * 100 + atoi(s.substr(sz(s) - 2, 2).c_str());
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    int balance = read();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        balance += read();
        if (balance % 100) ans++;
    }

    cout << ans << '\n';
    return 0;
}