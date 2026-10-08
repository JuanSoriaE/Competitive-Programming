// https://www.spoj.com/problems/TRYCOMP/
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
        int freq, end, index;
        Node() : freq(0), end(0), index(-1) { fill(links, links + 26, -1); }
    };
    vector<Node> trie;
    Trie() { trie.emplace_back(); }
    void insert(const string &s, int index) {
        int u = 0;
        for (char c : s) {
            int i = c - 'a';
            if (trie[u].links[i] == -1) {
                trie[u].links[i] = sz(trie);
                trie.emplace_back();
            }
            u = trie[u].links[i];
            trie[u].freq++;
        }
        trie[u].end++;
        trie[u].index = index;
    }
    void compute_ans(int u = 0) {
        for (int i = 0; i < 26; i++) {
            int v = trie[u].links[i];
            if (v == -1) continue;
            compute_ans(v);
            if (trie[v].end > trie[u].end) {
                trie[u].end = trie[v].end;
                trie[u].index = trie[v].index;
            }
        }
    }
    pair<int, int> get_ans(const string &s) {
        int u = 0;
        for (char c : s) {
            int i = c - 'a';
            if (trie[u].links[i] == -1) return {-1, -1};
            u = trie[u].links[i];
        }
        return {trie[u].end, trie[u].index};
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<string> v(n);
    Trie trie;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        trie.insert(v[i], i);
    }

    trie.compute_ans();

    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        auto [cnt, index] = trie.get_ans(s);
        if (cnt == -1) cout << "-1\n";
        else cout << v[index] << ' ' << cnt << '\n';
    }

    return 0;
}