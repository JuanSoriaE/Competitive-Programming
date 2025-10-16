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

// Implicit Treap
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

struct Node {
    int val, priority, size;
    bool rev;
    Node *l, *r;

    Node(int val) : val(val), priority(random(0, 1e9)), size(1), rev(0), l(nullptr), r(nullptr) {};
};

int get_size(Node *t) { return t ? t->size : 0; }

void update(Node *t) {
    t->size = get_size(t->l) + get_size(t->r) + 1;
}

void push(Node *t) {
    if (!t || !t->rev) return;

    swap(t->l, t->r);
    t->rev = 0;

    if (t->l) t->l->rev ^= 1;
    if (t->r) t->r->rev ^= 1;
}

pair<Node*, Node*> split(Node *t, int x, int add = 0) {
    if (!t) return {nullptr, nullptr};
    push(t);

    int cur_key = add + get_size(t->l) + 1;
    if (cur_key <= x) {
        auto [l, r] = split(t->r, x, cur_key);
        t->r = l;
        update(t);
        return {t, r};
    } else {
        auto [l, r] = split(t->l, x, add);
        t->l = r;
        update(t);
        return {l, t};
    }
}

Node* merge(Node *l, Node *r) {
    push(l); push(r);
    if (!l) return r;
    if (!r) return l;

    if (l->priority > r->priority) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

void dfs(Node *t, vector<int> &ans, int &idx) {
    push(t);
    if (!t) return;

    dfs(t->l, ans, idx);
    ans[idx++] = t->val;
    dfs(t->r, ans, idx);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q, m; cin >> n >> q >> m;
    Node *t = nullptr;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        t = merge(t, new Node(a));
    }

    while (q--) {
        int type, l, r; cin >> type >> l >> r;
        l--; r--;

        auto [a, b] = split(t, l);
        auto [c, d] = split(b, r - l + 1);
        if (type == 1) {
            auto [e, f] = split(c, r - l);
            t = merge(a, merge(f, merge(e, d)));
        } else {
            c->rev ^= 1;
            push(c);
            t = merge(a, merge(c, d));
        }
    }
    
    
    vector<int> ans(n);
    int idx = 0;
    dfs(t, ans, idx);

    for (int i = 0; i < m; i++) {
        int b; cin >> b;
        cout << ans[--b] << " ";
    }
    cout << "\n";

    return 0;
}