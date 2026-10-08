// https://codeforces.com/contest/456/problem/D
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
        bool win, lose;
        Node() : win(false), lose(false) { fill(links, links + 26, -1); }
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
    void dfs(int u = 0) {
        int children = 0;
        for (int i = 0; i < 26; i++) {
            int v = trie[u].links[i];
            if (v == -1) continue;

            dfs(v);
            trie[u].win |= !trie[v].win;
            trie[u].lose |= !trie[v].lose;
            children++;
        }
        if (children == 0)
            trie[u].lose = true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, k; cin >> n >> k;
    Trie trie;
    while (n--) {
        string s; cin >> s;
        trie.insert(s);
    }

    trie.dfs();

    bool w = trie.trie[0].win, l = trie.trie[0].lose;
    if (w && l) cout << "First";
    else if (w && !l) cout << (k & 1 ? "First" : "Second");
    else if (!w && l) cout << "Second";
    else cout << "Second";
    cout << '\n';

    return 0;
}