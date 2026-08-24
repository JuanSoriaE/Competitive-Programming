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
    vector<string> prev = {"*"};
    for (int i = 0; i < n; i++) {
        string emp(sz(prev[0]), '.');
        vector<string> cur;
        for (int j = 0; j < sz(prev); j++)
            cur.push_back(prev[j] + emp + prev[j]);
        for (int j = 0; j < sz(prev); j++)
            cur.push_back(emp + prev[j] + emp);
        for (int j = 0; j < sz(prev); j++)
            cur.push_back(prev[j] + emp + prev[j]);

        prev = cur;
    }

    for (string &s : prev)
        cout << s << '\n';

    return 0;
}