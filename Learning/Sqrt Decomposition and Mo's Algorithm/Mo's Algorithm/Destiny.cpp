// https://codeforces.com/contest/840/problem/D
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// Hilbert Curve Order
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
const int BLOCK_SIZE = 550;
struct Query {
    int l, r, k, i;
    uint64_t o;

    inline void calc_order() {
        o = hilbert_order(l, r, 21, 0);
    }

    bool operator<(const Query &other) const {
        return o < other.o;
    }
};

vector<int> a;
vector<int> mp;
const int TRIES = 80;

void add(int x) {
    mp[x]++;
}
void remove(int x) {
    mp[x]--;
}
// Randomized Algorithm
int get_answer(Query &q) {
    int &l = q.l, &r = q.r, &k = q.k;
    int res = INT_MAX;
    for (int j = 0; j < TRIES; j++) {
        int i = random(l, r);
        if (k * mp[a[i]] > (r - l + 1))
            res = min(res, a[i]);
    }
    return res == INT_MAX ? -1 : res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    a.resize(n); mp.resize(n + 1);
    for (int &i : a) cin >> i;

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r >> queries[i].k;
        queries[i].l--; queries[i].r--;
        queries[i].i = i;
        queries[i].calc_order();
    }

    sort(all(queries));
    
    vector<int> ans(q);
    int cur_l = 0, cur_r = -1;
    for (Query &q : queries) {
        while (cur_l > q.l)
            add(a[--cur_l]);
        while (cur_r < q.r)
            add(a[++cur_r]);
        while (cur_l < q.l)
            remove(a[cur_l++]);
        while (cur_r > q.r)
            remove(a[cur_r--]);

        ans[q.i] = get_answer(q);
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";

    return 0;
}