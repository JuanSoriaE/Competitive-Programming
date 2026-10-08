// https://judge.yosupo.jp/problem/set_xor_min
#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

struct Trie {
    struct Node {
        int links[2], freq;
        Node() : freq(0) { links[0] = links[1] = -1; }
    };
    vector<Node> trie;
    Trie() { trie.emplace_back(); }
    void insert(const int &x) {
        if (search(x)) return;
        int u = 0;
        for (int i = 31; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (trie[u].links[j] == -1) {
                trie[u].links[j] = sz(trie);
                trie.emplace_back();
            }
            u = trie[u].links[j];
            trie[u].freq++;
        }
    }
    void remove(const int &x) {
        if (!search(x)) return;
        int u = 0;
        for (int i = 31; i >= 0; i--) {
            int j = (x >> i) & 1;
            u = trie[u].links[j];
            trie[u].freq--;
        }
    }
    bool search(const int &x) {
        int u = 0;
        for (int i = 31; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (trie[u].links[j] == -1 ||
                !trie[trie[u].links[j]].freq)
                return false;
            u = trie[u].links[j];
        }
        return true;
    }
    int min_xor(const int &x) {
        int u = 0, res = 0;
        for (int i = 31; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (trie[u].links[j] != -1 &&
                trie[trie[u].links[j]].freq) {
                u = trie[u].links[j];
            } else {
                res |= (1 << i);
                u = trie[u].links[j ^ 1];
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> q;
    Trie trie;
    while (q--) {
        int op, x; cin >> op >> x;
        if (op == 0) trie.insert(x);
        else if (op == 1) trie.remove(x);
        else cout << trie.min_xor(x) << '\n';
    }
    return 0;
}