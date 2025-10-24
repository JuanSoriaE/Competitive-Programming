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

#define START 33
#define END 126
#define LEN 2

vector<string> seq;
void dfs(string &cur_seq, int i) {
    if (i == LEN) {
        seq.push_back(cur_seq);
        return;
    }

    for (char c = START; c <= END; c++) {
        cur_seq[i] = c;
        dfs(cur_seq, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    string cur_seq(LEN, '-');
    dfs(cur_seq, 0);

    for (int i = 0; i < n; i++)
        cout << "Aa0!" << seq[i] << seq[i] << '\n';

    return 0;
}