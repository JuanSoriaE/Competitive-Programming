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

string get_key(vector<int> &v) {
    string key = "";
    for (int &i : v)
    key += to_string(i) + ",";
    return key;
}

void solve() {
    string s, t; cin >> s >> t;
    umap<string, int> cnt;
    for (int i = 0; i < sz(t); i++) {
        vector<int> prefix(26, 0);
        for (int j = i; j < sz(t); j++) {
            prefix[t[j] - 'a']++;
            cnt[get_key(prefix)]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < sz(s); i++) {
        vector<int> prefix(26, 0);
        for (int j = i; j < sz(s); j++) {
            prefix[s[j] - 'a']++;
            string key = get_key(prefix);
            if (cnt.count(key))
            ans += cnt[key];
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}