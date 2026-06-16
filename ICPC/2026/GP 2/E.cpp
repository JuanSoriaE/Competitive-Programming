#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s; cin >> s;
    string ans = "";

    for (int i = 0; i  < sz(s);)
    if (s.substr(i, 6) == "mesero") {
        ans += "taquero";
        i += 6;
    } else {
        ans += s[i++];
    }

    cout << ans << '\n';

    return 0;
}