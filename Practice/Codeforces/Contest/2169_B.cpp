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
    string s; cin >> s;
    if (sz(s) == 1) {
        cout << "1\n";
        return;
    }

    if (s.find("**") != string::npos ||
        s.find("*<") != string::npos ||
        s.find(">*") != string::npos ||
        s.find("><") != string::npos) {
        cout << "-1\n";
        return;
    }

    int ans = 0, cur = 0;
    for (int i = 0; i < sz(s) && (s[i] == '<' || s[i] == '*'); i++)
        ans++;
    for (int i = sz(s) - 1; i >= 0 && (s[i] == '>' || s[i] == '*'); i--)
        cur++;
    ans = max(ans, cur);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}