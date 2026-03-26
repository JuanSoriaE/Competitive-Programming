#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define ii pair<int, int>

#define N 17
#define M 35

const vector<ii> OFFS = {{-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}};

vector<vector<int>> balls;
vector<int> cur_balls;

int m[N][M];
int ans = 0;

int calc() {
    int max_size = 0;
    for (int r = 0; r < N; r++)
    for (int c = 0; c < M; c++) {
        if (m[r][c] <= 0) continue;

        // BFS
        queue<ii> q; q.push({r, c});
        m[r][c] *= -1;
        int cur_size = 0;

        while (!q.empty()) {
            auto [cur_r, cur_c] = q.front(); q.pop();
            cur_size++;

            for (auto [x, y] : OFFS) {
                int new_r = cur_r + x, new_c = cur_c + y;
                bool is_in_bound = min(new_r, new_c) >= 0 && new_r < N && new_c < M;
                if (!is_in_bound ||
                    m[new_r][new_c] <= 0 ||
                    abs(m[new_r][new_c]) != abs(m[r][c]))
                    continue;
                m[new_r][new_c] *= -1;
                q.push({new_r, new_c});
            }
        }

        max_size = max(max_size, cur_size);
    }

    for (int r = 0; r < N; r++)
    for (int c = 0; c < M; c++)
        m[r][c] *= -1;

    return max_size;
}

void dfs(int balls_i, int l, int r) {
    if (balls_i == sz(balls)) {
        ans = max(ans, calc());
        return;
    }

    // Place at left
    for (int i = 0; i < sz(balls[balls_i]); i++)
        m[i][l] = balls[balls_i][i];

    dfs(balls_i + 1, l - 1, r);

    // Remove placed left
    for (int i = 0; i < sz(balls[balls_i]); i++)
        m[i][l] = 0;

    // Place at right
    for (int i = 0; i < sz(balls[balls_i]); i++)
        m[i][r - i] = balls[balls_i][i];

    dfs(balls_i + 1, l, r + 1);

    // Remove placed right
    for (int i = 0; i < sz(balls[balls_i]); i++)
        m[i][r - i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    for (int i = 0; i < N; i++) fill(m[i], m[i] + M, 0);

    int n; cin >> n;
    int total = 0, cur = 1;
    while (total < n) {
        int c; cin >> c;
        cur_balls.push_back(c);
        if (sz(cur_balls) == cur) {
            balls.push_back(cur_balls);
            cur_balls.clear();
            cur++;
        }
        total++;
    }
    if (!cur_balls.empty()) balls.push_back(cur_balls);

    m[0][M / 2] = balls[0][0];
    dfs(1, (M / 2) - 1, (M / 2) + 1);

    cout << ans << '\n';

    return 0;
}