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

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    set<int> st;
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        st.insert(a);
    }

    int x = 1;
    for (char &c : s) {
        x++;
        if (c == 'B')
        while (st.count(x)) x++;
        st.insert(x);

        if (c == 'B')
        while (st.count(x)) x++;
    }

    cout << st.size() << "\n";
    for (auto &a : st)
        cout << a << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}