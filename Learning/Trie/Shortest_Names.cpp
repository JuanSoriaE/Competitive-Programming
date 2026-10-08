// https://vjudge.net/problem/UVA-12506
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
        int links[26];
        Node() { fill(links, links + 26, -1); }
    };
    vector<Node> trie;
    Trie() { trie.emplace_back(); }
    void insert(const string &s) {
        int u = 0;
        for (char c : s) {
            int i = c - 'a';
            if (trie[u].links[i] == -1) {
                trie[u].links[i] = sz(trie);
                trie.emplace_back();
            }
            u = trie[u].links[i];
        }
    }
    int ans(int u = 0, int d = 0, int last_div = 0) {
        int children = 0;
        for (int i = 0; i < 26; i++)
        if (trie[u].links[i] != -1) children++;

        int ret = children == 0 ? last_div + 1 : 0;
        for (int i = 0; i < 26; i++) {
            if (trie[u].links[i] == -1) continue;
            ret += ans(trie[u].links[i], d + 1, children == 1 ? last_div : d);
        }

        return ret;
    }
};

void solve() {
    int n; cin >> n;
    Trie trie;
    while (n--) {
        string s; cin >> s;
        trie.insert(s);
    }
    cout << trie.ans() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}