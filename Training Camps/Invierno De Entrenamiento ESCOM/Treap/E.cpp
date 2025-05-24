#include <bits/stdc++.h>
using namespace std;

///implicit treap
///#pragma GCC optimize("O3")
///#pragma GCC target("tune=native") se pueden usar para optimizar xd ni idea para que sirvan pero sirven xd

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto randis = uniform_int_distribution<int>(numeric_limits<int>::min(), numeric_limits<int>::max());

struct Node {
	int v;
	int w, s;
	Node *l, *r;
	Node(int c) : v(c), w(randis(rng)), s(1), l(NULL), r(NULL) {}
    ///if you want to do the reverse operations
    ///a trick is multiply -1 the size
    ///instead of add the boolean
} *root;

inline int size(Node *t) { return t ? abs(t->s) : 0;}

void mergenodes(Node *& p, Node *l, Node *r){
    ///merge nodes
    p->s = size(l) + size(r);
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

void dfs(Node *node) {
    if (!node) return;

    push(node);
    dfs(node->l);
    cout << node->v << " ";
    dfs(node->r);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++)
        merge(root, root, new Node(i));

    Node *A, *B, *C;
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        split(root, A, B, a);
        split(B, B, C, b);
        merge(C, A, C);
        split(C, A, C, c);
        if (B) B->s = -B->s;
        merge(C, B, C);
        merge(root, A, C);
    }

    dfs(root);

    return 0;
}