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

inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string text, t;
    getline(cin, text);
    getline(cin, t);
    set<char> st;
    for (int i = 1; i < sz(t) - 1; i++) st.insert(t[i]);

    string ans = "";
    for (char &c : text) {
        if (st.count(c) || sz(ans) > 0 && ans[sz(ans) - 1] == c) continue;
        ans += c;
    }

    ltrim(ans); rtrim(ans);
    cout << ans << "\n";
    return 0;
}