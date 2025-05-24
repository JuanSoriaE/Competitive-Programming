#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define uset unordered_set
#define umap unordered_map

// Knuth–Morris–Pratt (KMP)
vector<int> prefix_function(string &s) {
    const int N = sz(s);
    vector<int> pi(N);
    for (int i = 1; i < N; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp_pattern_search(string &s, string &pattern) {
    vector<int> pi = prefix_function(pattern);
    vector<int> occurrences;
    int matched_pos = 0;
    for (int i = 0; i < sz(s); i++) {
        while (matched_pos > 0 && pattern[matched_pos] != s[i])
            matched_pos = pi[matched_pos - 1];
        if (pattern[matched_pos] == s[i])
            matched_pos++;
        if (matched_pos == sz(pattern)) {
            occurrences.push_back(i - sz(pattern) + 1);
            matched_pos = pi[matched_pos - 1];
        }
    }
    return occurrences;
}

// Palindromic Tree (eerTree)
struct Node {
    int length;
    map<char, int> edges;
    int suffix;
    Node(int l) : length(l), suffix(0) {}
    Node(int l, const map<char, int> &e, int s) : length(l), edges(e), suffix(s) {}
};

constexpr int even_root = 0;
constexpr int odd_root = 1;

vector<Node> eertree(const string &s) {
    vector<Node> tree = {
        Node(0, {}, odd_root),
        Node(-1, {}, odd_root)
    };
    int suffix = odd_root;
    int n, k;

    for (int i = 0; i < sz(s); i++) {
        char c = s[i];
        for (n = suffix; ; n = tree[n].suffix) {
            k = tree[n].length;
            int b = i - k - 1;
            if (b >= 0 && s[b] == c) break;
        }

        auto it = tree[n].edges.find(c);
        auto end = tree[n].edges.end();
        if (it != end) {
            suffix = it->second;
            continue;
        }

        suffix = sz(tree);
        tree.push_back(Node(k + 2));
        tree[n].edges[c] = suffix;
        if (tree[suffix].length == 1) {
            tree[suffix].suffix = 0;
            continue;
        }

        while (true) {
            n = tree[n].suffix;
            int b = i - tree[n].length - 1;
            if (b >= 0 && s[b] == c) break;
        }
        tree[suffix].suffix = tree[n].edges[c];
    }
    return tree;
}

vector<string> get_palindromes(vector<Node> &tree) {
    vector<string> palindromes;
    function<void(int, string)> dfs = [&dfs, &tree, &palindromes](int n, string p) {
        auto it = tree[n].edges.cbegin();
        auto end = tree[n].edges.cend();
        for (; it != end; it = next(it)) {
            char c = it->first;
            int m = it->second;

            string pl = c + p + c;
            palindromes.push_back(pl);
            dfs(m, pl);
        }
    };
    dfs(0, "");

    auto it = tree[1].edges.cbegin();
    auto end = tree[1].edges.cend();
    for (; it != end; it = next(it)) {
        char c = it->first;
        int n = it->second;

        string ct(1, c);
        palindromes.push_back(ct);

        dfs(n, ct);
    }

    return palindromes;
}

vector<Node> tree = eertree("eertree");
vector<string> palindromes = get_palindromes(tree);


int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}