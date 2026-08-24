#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 200000;
constexpr int MAX_Q = 200000;
constexpr int BLOCK_SIZE = 448;

int op_01[MAX_N], op_10[MAX_N];
bool ans[MAX_Q];

struct Query {
    int l, r, k, i;
    bool operator<(const Query &o) const {
        if (l / BLOCK_SIZE != o.l / BLOCK_SIZE)
            return l < o.l;
        return (l / BLOCK_SIZE) & 1 ? (r < o.r) : (r > o.r);
    }
};

Query queries[MAX_Q];

int op_01_mp[MAX_N];
int op_10_mp[MAX_N];
int distinct_01, distinct_10;
void add(int i) {
    if (op_01[i] != -1) {
        if (op_01_mp[op_01[i]]++ == 0)
            distinct_01++;
    }
    if (op_10[i] != -1) {
        if (op_10_mp[op_10[i]]++ == 0)
            distinct_10++;
    }
}
void remove(int i) {
    if (op_01[i] != -1) {
        if (--op_01_mp[op_01[i]] == 0)
            distinct_01--;
    }
    if (op_10[i] != -1) {
        if (--op_10_mp[op_10[i]] == 0)
            distinct_10--;
    }
}
bool get_ans(const int &k) {
    return min(distinct_01, distinct_10) <= k;
}

void reset(const int &n) {
    fill(op_01, op_01 + n, -1);
    fill(op_10, op_10 + n, -1);
    fill(op_01_mp, op_01_mp + n, 0);
    fill(op_10_mp, op_10_mp + n, 0);
    distinct_01 = distinct_10 = 0;
}

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    reset(n);
    for (int i = 0; i < n; i++) {
        if ((s[i] - '0') != i % 2) op_01[i] = 1;
        if ((s[i] - '0') != (i + 1) % 2) op_10[i] = 1;
    }

    if (op_01[0] == 1) op_01[0] = 0;
    if (op_10[0] == 1) op_10[0] = 0;
    for (int i = 1; i < n; i++) {
        if (op_01[i] != -1) {
            if (op_01[i - 1] != -1) op_01[i] = op_01[i - 1];
            else op_01[i] = i;
        }
        if (op_10[i] != -1) {
            if (op_10[i - 1] != -1) op_10[i] = op_10[i - 1];
            else op_10[i] = i;
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k;
        queries[i] = {--l, --r, k, i};
    }
    sort(queries, queries + q);

    int cur_l = 0, cur_r = -1;
    for (int j = 0; j < q; j++) {
        auto &[l, r, k, i] = queries[j];
        while (cur_l > l) add(--cur_l);
        while (cur_r < r) add(++cur_r);
        while (cur_l < l) remove(cur_l++);
        while (cur_r > r) remove(cur_r--);

        ans[i] = get_ans(k);
    }

    for (int i = 0; i < q; i++)
        cout << (ans[i] ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}