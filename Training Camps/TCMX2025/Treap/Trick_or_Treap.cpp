// http://codeforces.com/gym/102787/problem/Z
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

// Implicit Treap with Parent
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

struct Node {
    int val, priority, size;
    ll sum;
    Node *p, *l, *r;

    Node(int val) : val(val), priority(random(0, 1e9)), size(1), sum(val), p(nullptr), l(nullptr), r(nullptr) {};
};

int get_size(Node *t) { return t ? t->size : 0; }
ll get_sum(Node *t)  { return t ? t->sum : 0; }

void update(Node *t) {
    t->size = get_size(t->l) + get_size(t->r) + 1;
    t->sum = get_sum(t->l) + get_sum(t->r) + t->val;
}

pair<Node*, Node*> split(Node *t, int x, int add = 0) {
    if (!t) return {nullptr, nullptr};

    int cur_key = add + get_size(t->l) + 1;
    if (cur_key <= x) {
        pair<Node*, Node*> p = split(t->r, x, cur_key);
        if (t->r) t->r->p = nullptr;
        t->r = p.first;
        if (t->r) t->r->p = t;
        update(t);
        return {t, p.second};
    } else {
        pair<Node*, Node*> p = split(t->l, x, add);
        if (t->l) t->l->p = nullptr;
        t->l = p.second;
        if (t->l) t->l->p = t;
        update(t);
        return {p.first, t};
    }
}

Node* merge(Node *l, Node *r) {
    if (!l) return r;
    if (!r) return l;

    if (l->priority > r->priority) {
        if (l->r) l->r->p = nullptr;
        l->r = merge(l->r, r);
        if (l->r) l->r->p = l;
        update(l);
        return l;
    } else {
        if (r->l) r->l->p = nullptr;
        r->l = merge(l, r->l);
        if (r->l) r->l->p = r;
        update(r);
        return r;
    }
}

// Gets the parent of treap | O(log(n))
Node* get_parent(Node *t) {
    if (!t) return nullptr;

    while (t && t->p) t = t->p;
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> q;
    Node* nodes[q] = {nullptr};

    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int y; cin >> y;
            nodes[i] = new Node(y);
        } else if (type == 2) {
            int y, z; cin >> y >> z;
            y--; z--;

            Node *parent1 = get_parent(nodes[y]);
            Node *parent2 = get_parent(nodes[z]);
            if (parent1 != parent2)
                merge(parent1, parent2);
        } else if (type == 3) {
            int y, z; cin >> y >> z;
            y--;

            Node *parent = get_parent(nodes[y]);
            if (get_size(parent) > z)
                split(parent, z);
        } else {
            int y; cin >> y;
            y--;

            Node *parent = get_parent(nodes[y]);
            cout << get_sum(parent) << "\n";
        }
    }

    return 0;
}