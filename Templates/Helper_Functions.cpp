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

// Input and Output
string s;
while (getline(cin, s)) {
    istringstream extractor(s);
    string t;
    while (extractor >> t)
        cout << t << ' ';
    cout << '\n';
}

// Trim
string ltrim(const string &s) {
    size_t start = s.find_first_not_of(" \t\n\r\f\v");
    return start == string::npos ? "" : s.substr(start);
}
string rtrim(const string &s) {
    size_t end = s.find_last_not_of(" \t\n\r\f\v");
    return end == string::npos ? "" : s.substr(0, end + 1);
}
string trim(const string &s) {
    return ltrim(rtrim(s));
}

// Split string
vector<string> split(const string &s, char delimiter) {
    vector<string> res;
    size_t l = 0, r = s.find(delimiter);
    while (r != string::npos) {
        res.push_back(trim(s.substr(l, r - l)));
        l = r + 1;
        r = s.find(delimiter, l);
    }
    res.push_back(trim(s.substr(l)));
    return res;
}

// Floor and Ceiling Log2
int log2_floor(int x) {
    return 31 - __builtin_clz(x);
}
int log2_floor(ll x) {
    return 63 - __builtin_clzll(x);
}
int log2_ceiling(int x) {
    int floor = log2_floor(x);
    return floor + !((1 << floor) == x);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}