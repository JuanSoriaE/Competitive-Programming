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

string s;

pair<int, string> get_min(char c) {
    int res = 0;
    string _s = "";
    for (int i = 0; i < sz(s); i++) {
        if (s[i] != c) res++;
        _s += c;
        c = c == '0' ? '1' : '0';
    }
    return {res, _s};
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int k; cin >> k >> s;
    if (k == 2) {
        auto p1 = get_min('0'), p2 = get_min('1');
        if (p1.first < p2.first) cout << p1.first << ' '  << p1.second << '\n';
        else cout << p2.first << ' '  << p2.second << '\n';
        return 0;
    }

    int ans = 0;
    s += '2';
    for (int i = 1, cnt = 1; i < sz(s); i++) {
        if (s[i] != s[i - 1]) {
            if (cnt >= k) {
                char rep = s[i - 1] == '0' ? '1' : '0';
                ans += cnt / k;
                int need_to_rep = cnt / k;
                for (int j = i - cnt + k - 1; j < i - 1; j += k, need_to_rep--)
                    s[j] = rep;

                if (need_to_rep) s[i - 2] = rep;
            }
            cnt = 1;
        } else {
            cnt++;
        }
    }
    s.pop_back();

    cout << ans << ' ' << s << '\n';

    return 0;
}