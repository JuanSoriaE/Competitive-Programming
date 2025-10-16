// https://codeforces.com/problemset/problem/86/D
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

#define MAX_N 100000

inline uint64_t hilbert_order(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0;

    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotate_delta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotate_delta[seg]) & 3;
    int64_t sub_square_size = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * sub_square_size;
    int64_t add = hilbert_order(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (sub_square_size - add - 1);
    return ans;
}

// Mo's Algorithm
const int BLOCK_SIZE = 448;
struct Query {
    int l, r, i;
    uint64_t o;
    inline void calc_order() {
        o = hilbert_order(l, r, 21, 0);
    }
    bool operator<(const Query &other) const {
        return o < other.o;
    }
};

vector<int> a;
int mp[MAX_N + 1] = {0};
int _ans = 0;
void add(int i) {
    if (a[i] > MAX_N) return;
    if (mp[a[i]] == a[i]) _ans--;
    else if (mp[a[i]] + 1 == a[i]) _ans++;
    mp[a[i]]++;
}
void remove(int i) {
    if (a[i] > MAX_N) return;
    if (mp[a[i]] == a[i]) _ans--;
    else if (mp[a[i]] - 1 == a[i]) _ans++;
    mp[a[i]]--;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    a.resize(n); for (int &i : a) cin >> i;

    vector<Query> qs(q);
    for (int i = 0; i < q; i++) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].l--; qs[i].r--;
        qs[i].i = i;
        qs[i].calc_order();
    }

    // Mo's Algorithm
    sort(all(qs));
    vector<ll> ans(q);

    int cur_l = 0, cur_r = -1;
    for (auto &[l, r, i, o] : qs) {
        while (cur_l > l) add(--cur_l);
        while (cur_r < r) add(++cur_r);
        while (cur_l < l) remove(cur_l++);
        while (cur_r > r) remove(cur_r--);

        ans[i] = _ans;
    }

    for (ll &i : ans) cout << i << "\n";

    return 0;
}