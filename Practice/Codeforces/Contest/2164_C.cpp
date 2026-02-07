#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pq priority_queue

#define MAX_N 200000
#define MAX_M 200000

int swords_left[MAX_N], b[MAX_M];
pii ret_monsters[MAX_M];

void solve() {
    int n, m; cin >> n >> m;

    pq<int, vector<int>, greater<int>> swords;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        swords.push(a);
    }

    for (int i = 0; i < m; i++) cin >> b[i];

    int ret_m = 0, no_ret_m = 0;
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        if (c) ret_monsters[ret_m++] = {b[i], c};
        else b[no_ret_m++] = b[i];
    }

    sort(ret_monsters, ret_monsters + ret_m);

    // Kill monsters with c > 0
    int swords_left_i = 0, ans = 0;
    for (int i = 0; i < ret_m && !swords.empty(); i++) {
        while (!swords.empty() && swords.top() < ret_monsters[i].first) {
            int sword = swords.top(); swords.pop();
            swords_left[swords_left_i++] = sword;
        }

        if (!swords.empty() && swords.top() >= ret_monsters[i].first) {
            int sword = swords.top(); swords.pop();
            swords.push(max(sword, ret_monsters[i].second));
            ans++;
        }
    }

    while (!swords.empty()) {
        swords_left[swords_left_i++] = swords.top();
        swords.pop();
    }

    // Kill remaining
    sort(swords_left, swords_left + swords_left_i);
    sort(b, b + no_ret_m);

    int i = 0, j = 0;
    while (i < swords_left_i && j < no_ret_m) {
        if (swords_left[i] >= b[j]) ans++, i++, j++;
        else i++;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}