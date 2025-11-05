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

#define MAX_N 10000
pair<int, int> activities[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, x; cin >> n >> x;

    for (int i = 0; i < n; i++) {
        int s, d; cin >> s >> d;
        activities[i] = {s, s + d};
    }
    sort(activities, activities + n);

    //                    C        T
    pair<int, int> ans = {INT_MAX, INT_MAX};
    for (int i = 0; i <= 480; i++) {
        int cur = i, conflicts = 0;
        for (auto &[s, e] : activities) {
            while (cur <= e) {
                if (cur >= s) conflicts++;
                cur += x;
            }
        }
        ans = min(ans, {conflicts, i});
    }

    cout << ans.second << ' ' << ans.first << '\n';
    
    return 0;
}