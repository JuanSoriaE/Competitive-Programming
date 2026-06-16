#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 100

vector<string> v[MAX_N];

vector<string> split(const string &s, char delimiter) {
    vector<string> res;
    size_t l = 0, r = s.find(delimiter);
    while (r != string::npos) {
        res.push_back(s.substr(l, r - l));
        l = r + 1;
        r = s.find(delimiter, l);
    }
    res.push_back(s.substr(l));
    return res;
}

string join(vector<string> &v, string join_char) {
    string res = "";
    for (int i = 0; i < sz(v); i++)
        res += v[i] + (i == sz(v) - 1 ? "" : join_char);
    return res;
}

void print_v(vector<string> v) { for (auto &s : v) cout << "'" << s << "'\n"; }

bool all_digits(string &s) {
    for (auto &c : s)
    if (c < '0' || c > '9')
        return false;
    return sz(s);
}

bool needs_power_10(string &s) {
    if (s[0] != '1') return false;
    int k = 0;
    for (int i = 1; i < sz(s); i++)
    if (s[i] == '0') k++;
    return k == sz(s) - 1 && k >= 4;
}

bool needs_notation(string &s) {
    if (s[0] == '0') return false;
    int k = 0;
    for (int i = sz(s) - 1; i > 0 && s[i] == '0'; i--)
        k++;
    return k >= 4;
}

string convert_power_10(string &s) {
    return "10^{" + to_string(sz(s) - 1) + "}";
}

string convert_notation(string s) {
    int k = 0;
    while (s.back() == '0') {
        s.pop_back();
        k++;
    }
    return string(1, s[0]) + (sz(s) > 1 ? "." : "") + s.substr(1, sz(s) - 1) + "\\cdot10^{" + to_string(k + sz(s) - 1) + "}";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    string s; getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        v[i] = split(s, ' ');
        for (auto &t : v[i])
        if (all_digits(t)) {
            if (needs_power_10(t)) {
                t = convert_power_10(t);
            } else if (needs_notation(t)) {
                t = convert_notation(t);
            }
        }

        cout << join(v[i], " ") << '\n';
    }
    return 0;
}