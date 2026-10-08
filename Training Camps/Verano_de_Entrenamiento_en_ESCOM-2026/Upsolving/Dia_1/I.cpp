#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 50000;
constexpr int MAX_Q = 200000;
constexpr int MOD = 1000000007;

int a[MAX_N];

// Treap
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

struct Node {
    int val, p, size;
    ll evens, odds;
    Node *l, *r;
    Node(int val) : val(val), p(random(0, 1e9)), size(1), evens(val), odds(0), l(nullptr), r(nullptr) {};
};

int get_size(Node *t) { return t ? t->size : 0; }
ll get_evens(Node *t) { return t ? t->evens : 0; }
ll get_odds(Node *t) { return t ? t->odds : 0; }

void update(Node *t) {
    t->size = get_size(t->l) + get_size(t->r) + 1;
    t->evens = get_evens(t->l) +
        (get_size(t->l) & 1 ? 0 : t->val) +
        (get_size(t->l) & 1 ? get_evens(t->r) : get_odds(t->r));
    t->odds = get_odds(t->l) +
        (get_size(t->l) & 1 ? t->val : 0) +
        (get_size(t->l) & 1 ? get_odds(t->r) : get_evens(t->r));
}

pair<Node*, Node*> split(Node *t, int x) {
    if (!t) return {nullptr, nullptr};
    if (t->val <= x) {
        pair<Node*, Node*> p = split(t->r, x);
        t->r = p.first;
        update(t);
        return {t, p.second};
    } else {
        pair<Node*, Node*> p = split(t->l, x);
        t->l = p.second;
        update(t);
        return {p.first, t};
    }
}

Node* merge(Node *l, Node *r) {
    if (!l) return r;
    if (!r) return l;
    if (l->p > r->p) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

Node *t;

// Mo's
constexpr int BS = 142;

struct Query {
    int l, r, i;
    bool operator<(const Query &o) const {
        if (l / BS != o.l / BS)
            return l < o.l;
        return (l / BS) & 1 ? (r < o.r) : (r < o.r);
    }
};

Query queries[MAX_Q];
ll ans[MAX_Q];

void add(int i) {
    pair<Node*, Node*> p = split(t, a[i]);
    Node *new_node = new Node(a[i]);
    t = merge(p.first, merge(new_node, p.second));
}
void remove(int i) {
    pair<Node*, Node*> p = split(t, a[i]);
    pair<Node*, Node*> p2 = split(p.first, a[i] - 1);
    t = merge(p2.first, p.second);
}
ll get_answer() { return get_evens(t); }

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        queries[i] = {l, r, i};
    }

    sort(queries, queries + q);

    int cur_l = 0, cur_r = -1;
    for (int j = 0; j < q; j++) {
        auto &[l, r, i] = queries[j];

        while (cur_l > l) add(--cur_l);
        while (cur_r < r) add(++cur_r);
        while (cur_l < l) remove(cur_l++);
        while (cur_r > r) remove(cur_r--);

        ans[i] = get_answer();
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] % MOD << '\n';

    return 0;
}