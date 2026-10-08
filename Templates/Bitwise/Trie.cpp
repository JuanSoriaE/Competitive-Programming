#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

// Bitwise Trie
struct Trie {
    static const int B = 31;
    struct Node {
        int links[2], freq;
        Node() : freq(0) { links[0] = links[1] = -1; }
    };
    vector<Node> trie;

    Trie() { trie.emplace_back(); }
    void insert(const int &x) {
        int u = 0;
        for (int i = B - 1; i >= 0; i--) {
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
        int u = 0;
        for (int i = B - 1; i >= 0; i--) {
            int j = (x >> i) & 1;
            u = trie[u].links[j];
            trie[u].freq--;
        }
    }
    int max_xor(const int &x) {
        int u = 0, res = 0;
        for (int i = B - 1; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (trie[u].links[j ^ 1] != -1 &&
                trie[trie[u].links[j ^ 1]].freq)
                u = trie[u].links[j ^ 1], res |= (1 << i);
            else
                u = trie[u].links[j];
        }
        return res;
    }
    int min_xor(const int &x) {
        int u = 0, res = 0;
        for (int i = B - 1; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (trie[u].links[j] != -1 &&
                trie[trie[u].links[j]].freq)
                u = trie[u].links[j];
            else
                u = trie[u].links[j ^ 1], res |= (1 << i);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}