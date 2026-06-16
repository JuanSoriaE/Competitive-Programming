#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ull unsigned long long
#define ld long double

#define MAX_N 400000
#define MAX_R 100000

int r[MAX_N], k[MAX_N];
ull start[MAX_N];

struct FenwickTree {
    // sat_at
    vector<ull> bit;
    int n;

    FenwickTree(const int n) : n(n), bit(n) {}
    void update(int i, ull val) {
        for (; i < n; i = i | (i + 1))
            bit[i] = max(bit[i], val);
    }
    ull query(int r) {
        ull ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < n; i++) cin >> k[i];

    start[0] = 0;
    FenwickTree f(MAX_R + 1);
    f.update(r[0], r[0] + k[0]);
    for (int i = 1; i < n; i++) {
        start[i] = r[i] < r[i - 1] ? start[i - 1] + 1 : f.query(r[i]);
        f.update(r[i], start[i] + r[i] + k[i]);
    }

    cout << f.query(MAX_R) << '\n';

    return 0;
}