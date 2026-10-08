#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

constexpr int MAX_N = 100000;

pair<int, int> invs[MAX_N];
pair<int, int> start[MAX_N], _end[MAX_N];

struct Response {
    char c;
    int x, y;
};
Response res[MAX_N];

vector<int> adj[MAX_N];
bool vst[MAX_N];

void dfs(int u, Response &final_res) {
    vst[u] = true;
    for (int &v : adj[u]) {
        res[v] = final_res;
        dfs(v, final_res);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int f, n; cin >> f >> n;
    map<int, int> friend_to_i;
    for (int i = 0; i < n; i++) {
        cin >> invs[i].first >> invs[i].second;
        friend_to_i[invs[i].first] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> res[i].c;
        if (res[i].c == 'A') cin >> res[i].x >> res[i].y;
        else if (res[i].c == 'T') {
            cin >> res[i].x;
            if (friend_to_i.count(res[i].x))
                adj[friend_to_i[res[i].x]].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (res[i].c == 'T' || vst[i]) continue;
        dfs(i, res[i]);
    }

    int m = 0;
    for (int i = 0; i < n; i++)
    if (res[i].c == 'A') {
        start[m] = {res[i].x, invs[i].second};
        _end[m++] = {res[i].x + res[i].y, invs[i].second};
    }

    sort(start, start + m);
    sort(_end, _end + m);

    int s = 0, e = 0;
    ll cur = 0, ans = 0;
    while (s < m) {
        if (start[s].first < _end[e].first)
            cur += start[s++].second;
        else
            cur -= _end[e++].second;
        ans = max(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}