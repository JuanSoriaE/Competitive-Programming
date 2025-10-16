#include <bits/stdc++.h>
using namespace std;

// #define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define uset unordered_set
#define umap unordered_map

// Sqrt Decomposition (Update single element)
struct Sqrt {
    int block_size;
    vector<int> a;
    vector<ll> sum;

    Sqrt(vector<int> &a) : block_size(ceil(sqrt(sz(a)))), a(a), sum(block_size, 0) {
        for (int i = 0; i < sz(a); i++) sum[i / block_size] += a[i];
    };

    void update(int i, int x) {
        sum[i / block_size] += x - a[i];
        a[i] = x;
    }
    ll query(int l, int r) {
        ll res = 0;
        while (l <= r && l % block_size != 0)
            res += a[l++];
        while (l + block_size - 1 <= r)
            res += sum[l / block_size], l += block_size;
        while (l <= r)
            res += a[l++];
        return res;
    }
};

// Sqrt Decomposition (Update range)
struct Sqrt {
    int block_size;
    vector<ll> a, sum, add;

    Sqrt(vector<ll> &a) : block_size(ceil(sqrt(sz(a)))), a(a),
        sum(block_size, 0), add(block_size, 0) {
        for (int i = 0; i < sz(a); i++) sum[i / block_size] += a[i];
    };

    void update(int l, int r, int x) {
        while (l <= r && l % block_size != 0)
            sum[l / block_size] += x, a[l] += x, l++;
        while (l + block_size - 1 <= r)
            sum[l / block_size] += x * block_size, add[l / block_size] += x, l += block_size;
        while (l <= r)
            sum[l / block_size] += x, a[l] += x, l++;
    }
    ll query(int l, int r) {
        ll res = 0;
        while (l <= r && l % block_size != 0)
            res += a[l] + add[l / block_size], l++;
        while (l + block_size - 1 <= r)
            res += sum[l / block_size], l += block_size;
        while (l <= r)
            res += a[l] + add[l / block_size], l++;
        return res;
    }
};

// Mo's Algorithm
const int BLOCK_SIZE = 317; // sqrt(10^5)
struct Query {
    int l, r, i;

    bool operator<(const Query &other) const {
        if (l / BLOCK_SIZE != other.l / BLOCK_SIZE)
            return l < other.l;
        return (l / BLOCK_SIZE) & 1 ? (r < other.r) : (r > other.r);
    }
};

// O(F)
void add(int i) {}
void remove(int i) {}
int get_answer() { return 0; }

// Mo's Algorithm | O((n + q)Fsqrt(n))
sort(all(queries));
vector<int> ans(sz(queries));

int cur_l = 0, cur_r = -1;
for (auto &[l, r, i] : queries) {
    while (cur_l > l) add(--cur_l);
    while (cur_r < r) add(++cur_r);
    while (cur_l < l) remove(cur_l++);
    while (cur_r > r) remove(cur_r--);

    ans[i] = get_answer();
}

// Speedup: Process queries in order given by Hilbert Curve | O(nFsqrt(q))
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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}