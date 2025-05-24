#include <bits/stdc++.h>
using namespace std;

int cnt(string &s, string t) {
    const int N = s.size(), M = t.size();
    int cnt = 0, j;
    for (int i = 0; i < N - M + 1; i++) {
        j = 0;
        while (j < M && s[i + j] == t[j])
            j++;

        cnt += j == t.size();
    }

    return cnt;
}

int solve() {
    int n; cin >> n;
    string s; cin >> s;

    int map_cnt = cnt(s, "map"),
        pie_cnt = cnt(s, "pie"),
        mapie_cnt = cnt(s, "mapie");
    
    return map_cnt + pie_cnt - mapie_cnt;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}