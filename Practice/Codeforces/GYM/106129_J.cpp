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

int n; string s;

// 0 or 1
bool all_same() {
    bool all_0 = true, all_1 = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') all_1 = false;
        else if (s[i] == '1') all_0 = false;
        else if (s[i] == '2') return false;
    }
    return all_0 || all_1;
}

void encode() {
    if (all_same()) return;

    int first_1 = INT_MAX;
    for (int i = 0; i < n; i++)
    if (s[i] == '1') first_1 = min(first_1, i);

    for (int i = 0; i <= first_1; i++)
    s[i] = '2';
}

void decode() {
    if (all_same()) return;

    int cnt_2 = 0;
    for (int i = 0; i < n; i++)
    if (s[i] == '2') cnt_2++;

    if (cnt_2 == n) {
        for (int i = 0; i < n - 1; i++) s[i] = '0';
        s[n - 1] = '1';
        return;
    }

    int end = n - 1;
    for (int i = 0; i < n - 1; i++)
    if (s[i] == '2' && s[i + 1] != '2') end = i;

    string res = "";
    for (int i = 0; i < cnt_2 - 1; i++)
        res += '0';
    res += '1';

    for (int i = (end + 1) % n, cnt = 0; cnt < n - cnt_2; i = (i + 1) % n, cnt++)
        res += s[i];
    s = res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string t; cin >> t;
    cin >> n >> s;
    if (t == "Encode") encode();
    else decode();

    cout << s << '\n';
    cout.flush();

    return 0;
}