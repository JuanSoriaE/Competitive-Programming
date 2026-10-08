#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 1000000;

pair<int, char> X[MAX_N], Y[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    int total_w = 0;
    for (int i = 0; i < n; i++) {
        int x, y; char p; cin >> x >> y >> p;
        X[i] = {x, p}; Y[i] = {y, p};
        if (p == 'w') total_w++;
    }
    sort(X, X + n);
    sort(Y, Y + n);

    int ans = 0, cur_b = 0;
    for (int i = 0; i < n; i++) {
        if (X[i].second == 'b') cur_b++;
        while (i + 1 < n && X[i + 1].second == X[i].second) {
            if (X[i + 1].second == 'b') cur_b++;
            i++;
        }

        int cur_w = i + 1 - cur_b;
        int score_1 = cur_b + total_w - cur_w,
            score_2 = cur_w + (n - total_w) - cur_b;
        ans = max({ans, score_1, score_2});
    }

    cur_b = 0;
    for (int i = 0; i < n; i++) {
        if (Y[i].second == 'b') cur_b++;
        while (i + 1 < n && Y[i + 1].second == Y[i].second) {
            if (Y[i + 1].second == 'b') cur_b++;
            i++;
        }

        int cur_w = i + 1 - cur_b;
        int score_1 = cur_b + total_w - cur_w,
            score_2 = cur_w + (n - total_w) - cur_b;
        ans = max({ans, score_1, score_2});
    }

    cout << ans << '\n';

    return 0;
}