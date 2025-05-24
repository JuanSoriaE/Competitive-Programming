#include <bits/stdc++.h>
using namespace std;

// implicit treap
///#pragma GCC optimize("O3")
///#pragma GCC target("tune=native") se pueden usar para optimizar xd ni idea para que sirvan pero sirven xd

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto randis = uniform_int_distribution<int>(numeric_limits<int>::min(), numeric_limits<int>::max());

struct Node {
	long long v, sv;
	int w, s;
	Node *l, *r;
	Node(long long c) : v(c), sv(c), w(randis(rng)), s(1), l(NULL), r(NULL) {}
    ///if you want to do the reverse operations
    ///a trick is multiply -1 the size
    ///instead of add the boolean
} *root;

inline int size(Node *t) { return t ? abs(t->s) : 0;}

void mergenodes(Node *& p, Node *l, Node *r){
    ///merge nodes
    p->s = size(l) + size(r);
    p->sv = l->sv + r->sv;
    ///operations to merge the nodes
}

void push(Node *t){
    if(!t) return;
    ///operations for lazy
    ///reverse a treap with the trick
    if(t->s < 0){
        swap(t->l, t->r);
        if(t->l) t->l->s = -t->l->s;
        if(t->r) t->r->s = -t->r->s;
        t->s = - t->s;
    }
}

void update(Node *t){
    if(!t) return;
    ///reset value of the node t
    t->s = 1;
    t->sv = t->v;
    push(t->l);
    push(t->r);
    ///whatever operations to reset value
    if(t->l) mergenodes(t, t->l, t);
    if(t->r) mergenodes(t, t, t->r);
}

void split(Node *t, Node *&l, Node *&r, int v) {
	if (!t) {
		l = r = NULL;
		return;
	}
    push(t);
	if (size(t->l) < v) {
		split(t->r, t->r, r, v - size(t->l) - 1);
		l = t;
	} else {
		split(t->l, l, t->l, v);
		r = t;
	}
    update(t);
}

void merge(Node *&t, Node *l, Node *r) {
	push(l), push(r);
	if(!l || !r){
        t = (l) ? l : r;
        return;
	}
	if (l->w < r->w) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}
	update(t);
}

int main() {
    int n, m, aux; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> aux;

        merge(root, root, new Node(aux));
    }
    
    Node *a, *b, *c;
    int t, l, r;
    while (m--) {
        cin >> t >> l >> r;
        split(root, a, b, l - 1);
        split(b, b, c, r - l + 1);

        if (t == 1) b->s = - b->s;
        else cout << b->sv << "\n";

        merge(root, a, b);
        merge(root, root, c);
    }

    return 0;
}