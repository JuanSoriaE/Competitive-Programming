// https://codeforces.com/contest/706/problem/D
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
    void erase(const int &x) {
        int u = 0;
        for (int i = 31; i >= 0; i--) {
            int j = (x >> i) & 1;
            u = trie[u].links[j];
            trie[u].freq--;
        }
    }
    int max_xor(const int &x) {
        int res = 0, u = 0;
        for (int i = 31; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (trie[u].links[j ^ 1] != -1 && 
                trie[trie[u].links[j ^ 1]].freq) {
                u = trie[u].links[j ^ 1];
                res |= (1 << i);
            } else {
                u = trie[u].links[j];
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q; cin >> q;
    Trie trie;
    trie.insert(0);
    while (q--) {
        char c; int x; cin >> c >> x;
        if (c == '+') trie.insert(x);
        else if (c == '-') trie.erase(x);
        else cout << trie.max_xor(x) << '\n';
    }
    return 0;
}