#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 300000;

ll c[MAX_N];

int n;
ll all_cards;

struct Node {
    int val, i;
    Node() : val(-1), i(0) {}
    Node(int val, int i) : val(val), i(i) {}

    Node operator+(const Node& r) const {
        if (val == -1) return r;
        if (r.val == -1 or val > r.val) return *this;
        if (val == r.val && i < r.i) return *this;
        return r;
    }
};

struct ST_Max_Indx {
    int n;
    vector<Node> tree;

    ST_Max_Indx(vector<int> &a) : n(sz(a)), tree(2 * n) {
        for (int i = 0; i < n; ++i)
            tree[n + i] = Node(a[i], i);
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    Node query(int l, int r) {
        Node res_left, res_right;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res_left = res_left + tree[l++];
            if (r & 1) res_right = tree[--r] + res_right;
        }
        return res_left + res_right;
    }
};

int ans = 0;
ll dfs(ST_Max_Indx &st, int l = 0, int r = n - 1) {
    if (l == r) return c[l];
    if (l > r) return 0;

    int i = st.query(l, r).i;
    ll left = dfs(st, l, i - 1);
    ll right = dfs(st, i + 1, r);

    if ((left | right) == all_cards) ans++;
    return left | right | c[i];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int k; cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        c[i] = (1LL << (x - 1));
    }
    all_cards = (1LL << k) - 1;

    ST_Max_Indx st(h);

    dfs(st);
    cout << ans << '\n';

    return 0;
}