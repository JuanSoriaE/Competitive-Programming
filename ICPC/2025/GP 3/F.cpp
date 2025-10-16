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

// U D L R
const vector<pair<int, int>> OFFS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
int start_r, start_c, end_r, end_c;

int get_off_i(char &c) {
    if (c == 'U') return 0;
    else if (c == 'D') return 1;
    else if (c == 'L') return 2;
    return 3;
}

bool is_valid(vector<string> &mat, int r, int c) {
    return min(r, c) >= 0 && r < n && c < m && mat[r][c] == '0';
}

// d, new_r, new_c
vector<int> execute(vector<string> &mat, string &inst, int r, int c) {
    int d = 0;
    for (char &ch : inst) {
        int off_i = get_off_i(ch);
        int new_r = r + OFFS[off_i].first, new_c = c + OFFS[off_i].second;

        if (!is_valid(mat, new_r, new_c))
            continue;

        r = new_r; c = new_c;
        d++;
    }

    return {d, r, c};
}

int dijkstra(vector<string> &mat, vector<string> &insts) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    pq.push({0, start_r, start_c});
    dist[start_r][start_c] = 0;

    while (!pq.empty()) {
        vector<int> cur = pq.top(); pq.pop();
        int d = cur[0], r = cur[1], c = cur[2];

        if (r == end_r && c == end_c)
            return d;
        if (d >= dist[r][c])
            continue;

        for (string &inst : insts) {
            vector<int> new_cur = execute(mat, inst, r, c);
            int new_d = new_cur[0], new_r = new_cur[1], new_c = new_cur[2];
            new_d += d;

            if (new_d >= dist[new_r][new_c])
                continue;

            dist[new_r][new_c] = new_d;
            pq.push({new_d, new_r, new_c});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    vector<string> mat(n);
    for (int r = 0; r < n; r++)
        cin >> mat[r];

    cin >> start_r >> start_c >> end_r >> end_c;

    int k; cin >> k;
    vector<string> insts(k);
    for (int i = 0; i < k; i++) cin >> insts[i];

    cout << dijkstra(mat, insts) << "\n";
    return 0;
}