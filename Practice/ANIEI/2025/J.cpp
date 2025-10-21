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

struct Activity {
    int h, l, r;
    bool operator<(const Activity &o) const {
        return r < o.r;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, T; cin >> n >> T;
    vector<Activity> activities;
    for (int i = 0; i < n; i++) {
        Activity act;
        cin >> act.h;
        int d, t; cin >> d >> t;
        while (t--) {
            int l; cin >> l;
            if (l > T) continue;

            act.l = l; act.r = l + d;
            activities.push_back(act);
        }
    }

    sort(all(activities));
    n = sz(activities);

    vector<int> prev(n);
    for (int i = 0; i < n; i++) {
        int prev_i = -1;
        for (int j = i - 1; prev_i == -1 && j >= 0; j--)
        if (activities[j].r <= activities[i].l) prev_i = j;

        prev[i] = prev_i;
    }

    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = max(i > 0 ? dp[i - 1] : 0, activities[i].h + (prev[i] >= 0 ? dp[prev[i]] : 0));
    }

    cout << dp[n - 1] << '\n';

    return 0;
}