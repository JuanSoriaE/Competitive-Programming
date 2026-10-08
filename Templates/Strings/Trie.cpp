#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

// Trie (Prefix Tree)
struct Trie {
    struct Node {
        int links[26];
        int freq, end;
        Node() : freq(0), end(0) { fill(links, links + 26, -1); }
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
            trie[u].freq++;
        }
        trie[u].end++;
    }
    void remove(const string &s) {
        int u = 0;
        for (char c : s) {
            int i = c - 'a';
            u = trie[u].links[i];
            trie[u].freq--;
        }
        trie[u].end--;
    }
    bool search(const string &s) {
        int u = 0;
        for (char c : s) {
            int i = c - 'a';
            if (trie[u].links[i] == -1 ||
                !trie[trie[u].links[i]].freq) return false;
            u = trie[u].links[i];
        }
        return trie[u].end;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}