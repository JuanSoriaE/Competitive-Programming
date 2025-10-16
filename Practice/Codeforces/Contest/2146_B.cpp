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

#define MAX_M 100000

int cnt[MAX_M + 1];

string solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) cnt[i] = 0;

    vector<vector<int>> sts(n);
    for (auto &st : sts) {
        int l; cin >> l;
        st.resize(l);
        for (int &a : st) {
            cin >> a; cnt[a]++;
        }
    }

    for (int i = 1; i <= m; i++)
    if (cnt[i] == 0) return "NO";

    int ans = 1;
    for (auto &st : sts) {
        bool valid = 1;
        for (int &a : st)
        if (cnt[a] - 1 == 0) {
            valid = 0;
            break;
        }

        ans += valid;
    }

    return ans >= 3 ? "YES" : "NO";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}