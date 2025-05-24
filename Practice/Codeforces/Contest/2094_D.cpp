#include <bits/stdc++.h>
using namespace std;

bool is_possible(int a, int b) {
    return a <= b && b <= 2 * a;
}

string solve() {
    string p, s; cin >> p >> s;
    vector<pair<char, int>> p_comp, s_comp;
    int cnt = 1;
    for (int i = 1; i < p.size(); i++) {
        if (p[i] == p[i - 1]) {
            cnt++;
            continue;
        }
        
        p_comp.push_back({p[i - 1], cnt});
        cnt = 1;
    }
    p_comp.push_back({p[p.size() - 1], cnt});

    cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
            continue;
        }

        s_comp.push_back({s[i - 1], cnt});
        cnt = 1;
    }
    s_comp.push_back({s[s.size() - 1], cnt});

    if (p_comp.size() != s_comp.size()) return "NO";

    for (int i = 0; i < p_comp.size(); i++)
    if (p_comp[i].first != s_comp[i].first ||
        !is_possible(p_comp[i].second, s_comp[i].second))
        return "NO";

    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
    return 0;
}