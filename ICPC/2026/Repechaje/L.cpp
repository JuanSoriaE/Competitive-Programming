#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;

    set<string> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= sz(s); j++) {
            string p = s.substr(0, j);

            if (st.count(p)) ans = max(ans, j);
            else st.insert(p);
        }
    }
    cout << ans << '\n';

    return 0;
}