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
    Node *l, *r;

    Node(int val) : val(val), priority(random(0, 1e9)), size(1), l(nullptr), r(nullptr) {};
};

int get_size(Node *t) { return t ? t->size : 0; }

void update(Node *t) {
    t->size = get_size(t->l) + get_size(t->r) + 1;
}

// Splits treap {x elements, n - x elements} | O(log(n))
pair<Node*, Node*> split(Node *t, int x, int add = 0) {
    if (!t) return {nullptr, nullptr};

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

void dfs(Node *t) {
    if (!t) return;

    dfs(t->l);
    cout << t->val << " ";
    dfs(t->r);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    Node *t = nullptr;
    for (int i = 1; i <= n; i++)
        t = merge(t, new Node(i));

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (b <= a) continue;

        int win_size = min(b - a, n - b);

        pair<Node*, Node*> p1 = split(t, a);
        pair<Node*, Node*> p2 = split(p1.second, win_size);
        pair<Node*, Node*> p3 = split(p2.second, get_size(p2.second) - (n - b));
        pair<Node*, Node*> p4 = split(p3.second, win_size);

        t = merge(p1.first, merge(p4.first, merge(p3.first, merge(p2.first, p4.second))));
    }

    dfs(t); cout << "\n";
    
    return 0;
}