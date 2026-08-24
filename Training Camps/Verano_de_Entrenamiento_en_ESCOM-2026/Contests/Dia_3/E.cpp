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
    vector<string> a(n);
    map<int, int> mp;
    ll ans = 0;
    for (string &s : a) {
        cin >> s;
        int mask = 0;
        for (char &c : s)
            mask ^= (1 << (c - 'a'));

        ans += mp[mask];
        for (int i = 0; i < 26; i++)
            ans += mp[(mask ^ (1 << i))];

        mp[mask]++;
    }
    cout << ans << '\n';

    return 0;
}