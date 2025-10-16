// https://www.spoj.com/problems/ORDERSET/en/
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

// Basic Treap
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

// Splits treap {<=x, >x} | O(log(n))
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

// Merges two treaps | O(log(n))
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

// BST Operations
// Checks if x is in treap | O(log(n))
bool search(Node *t, int x) {
    if (!t) return 0;
    if (t->val == x) return 1;

    return search(x < t->val ? t->l : t->r, x);
}

// Inserts x in treap | O(log(n))
Node* insert(Node *t, int x) {
    if (search(t, x)) return t;

    pair<Node*, Node*> p = split(t, x);
    Node *new_node = new Node(x);
    return merge(p.first, merge(new_node, p.second));
}

// Removes all the elements equal to x in treap | O(log(n))
Node* remove(Node *t, int x) {
    pair<Node*, Node*> p1 = split(t, x);
    pair<Node*, Node*> p2 = split(p1.first, x - 1); // Deleted in p2.second
    return merge(p2.first, p1.second);
}

// Get the kth element in treap | O(log(n))
int get_kth(Node *t, int k) {
    if (!t) return -1;
    if (get_size(t->l) + 1 == k) return t->val;

    if (get_size(t->l) + 1 > k)
        return get_kth(t->l, k);
    else
        return get_kth(t->r, k - (get_size(t->l) + 1));
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> q;
    
    Node *t = nullptr;
    while (q--) {
        char type; cin >> type;
        int x; cin >> x;

        if (type == 'I')
            t = insert(t, x);
        else if (type == 'D')
            t = remove(t, x);
        else if (type == 'K')
            cout << (x > get_size(t) ? "invalid" : to_string(get_kth(t, x))) << "\n";
        else {
            pair<Node*, Node*> p = split(t, x - 1);
            cout << get_size(p.first) << "\n";
            t = merge(p.first, p.second);
        }
    }

    return 0;
}