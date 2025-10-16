// https://judge.yosupo.jp/problem/range_reverse_range_sum
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
int random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

struct Node {
    int val, priority, size;
    ll sum;
    bool rev;
    Node *l, *r;

    Node(int val) : val(val), priority(random(0, 1e9)), size(1),
        sum(val), rev(0), l(nullptr), r(nullptr) {};
};

int get_size(Node *t) { return t ? t->size : 0; }
ll get_sum(Node *t) { return t ? t->sum : 0; }

void update(Node *t) {
    t->size = get_size(t->l) + get_size(t->r) + 1;
    t->sum = get_sum(t->l) + get_sum(t->r) + t->val;
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
        pair<Node*, Node*> p = split(t->r, x, cur_key);
        t->r = p.first;
        update(t);
        return {t, p.second};
    } else {
        pair<Node*, Node*> p = split(t->l, x, add);
        t->l = p.second;
        update(t);
        return {p.first, t};
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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q; cin >> n >> q;
    Node *t = nullptr;
    for (int i = 0; i < n; i++) {
        int aux; cin >> aux;
        t = merge(t, new Node(aux));
    }


    while (q--) {
        int type, l, r; cin >> type >> l >> r;

        pair<Node*, Node*> p1 = split(t, l);
        pair<Node*, Node*> p2 = split(p1.second, r - l);
        if (type == 0) {
            if (p2.first) p2.first->rev ^= 1;
            push(p2.first);
        } else {
            cout << get_sum(p2.first) << "\n";
        }

        t = merge(p1.first, merge(p2.first, p2.second));
    }

    return 0;
}