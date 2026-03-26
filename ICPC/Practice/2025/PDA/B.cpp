#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define ii pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) pq.push({a[i], i});
    }

    vector<ii> ans;
    for (int i = 0; i < n - 1; i++) {
        while (pq.top().first < a[i]) {
            auto [x, j] = pq.top(); pq.pop();
            if (j <= i) continue;

            ans.push_back({i, j});
            int s = a[i] + x;
            a[i] = s / 2; a[j] = ceil(s, 2);
            pq.push({a[j], j});
        }
    }

    cout << ans.size() << '\n';
    for (auto &[i, j] : ans)
    cout << (i + 1) << ' ' << (j + 1) << '\n';

    return 0;
}