#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

void dfs(int n, char from, char to, char aux, vector<string> &ans) {
    if (n == 0) return;
    dfs(n - 1, from, aux, to, ans);
    ans.push_back({from, ' ', to});
    dfs(n - 1, aux, to, from, ans);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, k; cin >> n >> k;

    if ((1 << n) - 1 > k) {
        cout << "N\n";
        return 0;
    }

    vector<string> ans;
    dfs(n, 'A', 'C', 'B', ans);

    int extra = k - (1 << n) + 1;
    if (extra & 1)
        ans[0] = ans[0] == "A B" ? "A C\nC B" : "A B\nB C";

    cout << "Y\n";
    for (string &s : ans)
        cout << s << '\n';

    for (int i = 0; i < extra / 2; i++)
        cout << "C B\nB C\n";

    return 0;
}