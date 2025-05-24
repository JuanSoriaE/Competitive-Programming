#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define lli long long int
#define ld long double
#define uset unordered_set
#define umap unordered_map

vector<int> mp(1 << 26, -1);
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;

    int mask = 0, ans = 1;
    for (int i = 0; i < n; i++) {
        mask ^= (1 << (s[i] - 'a'));

        if (mp[mask] != -1 || mask == 0)
            ans = max(ans, i - mp[mask]);
        else
            mp[mask] = i;

        for (int j = 0; j < 26; j++) {
            int temp = mask ^ (1 << j);
            if (mp[temp] != -1 || temp == 0)
                ans = max(ans, i - mp[temp]);
        }
    }
    cout << ans << "\n";

    return 0;
}