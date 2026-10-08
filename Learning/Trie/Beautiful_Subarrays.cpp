// https://codeforces.com/problemset/problem/665/E
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
    ll get_res(const int &x, const int &k) {
        int u = 0; ll res = 0;
        for (int i = B - 1; i >= 0; i--) {
            int j = (x >> i) & 1;
            if ((k >> i) & 1) {
                if (trie[u].links[j ^ 1] != -1)
                    u = trie[u].links[j ^ 1];
                else
                    break;
            } else {
                if (trie[u].links[j ^ 1] != -1)
                    res += trie[trie[u].links[j ^ 1]].freq;

                if (trie[u].links[j] != -1)
                    u = trie[u].links[j];
                else
                    break;
            }
        }
        if (trie[u].links[0] == -1 && trie[u].links[1] == -1)
            res += trie[u].freq;
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, k; cin >> n >> k;
    Trie trie; trie.insert(0);
    int cur = 0; ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cur ^= a;
        ans += trie.get_res(cur, k);
        trie.insert(cur);
    }
    cout << ans << '\n';
    return 0;
}