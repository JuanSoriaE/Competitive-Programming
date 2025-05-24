#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define lli long long int
#define ld long double
#define uset unordered_set
#define umap unordered_map

vector<vector<int>> rotate(vector<vector<int>> &m) {
    const int N = sz(m), M = sz(m[0]);
    vector<vector<int>> rotated(M, vector<int>(N));
    for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
        rotated[j][N - 1 - i] = m[i][j];
    return rotated;
}

vector<vector<int>> mirror(vector<vector<int>> &m) {
    const int N = sz(m), M = sz(m[0]);
    vector<vector<int>> mirrored(M, vector<int>(N));
    for (int r = 0; r < N; r++) {
        mirrored[r] = m[r];
        reverse(all(mirrored[r]));
    }
    return mirrored;
}

const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void spiral(vector<vector<int>> &m) {
    const int N = sz(m), M = sz(m[0]);
    int cur = 0;
    int row = 0, col = 0, dir_idx = 0, l = 0, r = M - 1, t = 1, b = N - 1;
    for (int i = 0; i < N * M; i++) {
        m[row][col] = cur++;

        if ((dir_idx == 0 && col == r) || (dir_idx == 1 && row == b) ||
            (dir_idx == 2 && col == l) || dir_idx == 3 && row == t) {
            if (col == r) r--;
            else if (row == b) b--;
            else if (col == l) l++;
            else if (row == t) t++;

            (dir_idx += 1) %= 4;
        }

        row += dirs[dir_idx].first;
        col += dirs[dir_idx].second;
    }
}

ll kadane(vector<int> &v) {
    ll cur_sum = 0, max_sum = 0;
    for (int &i : v) {
        cur_sum += i;
        cur_sum = max(cur_sum, 0ll);
        max_sum = max(max_sum, cur_sum);
    }
    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++)
        cin >> m[r][c];

    vector<vector<int>> order(n, vector<int>(n));
    spiral(order);

    ll ans = 0;
    vector<int> arr(n * n);
    for (int i = 0; i < 4; i++) {
        for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            arr[order[r][c]] = m[r][c];
        ans = max(ans, kadane(arr));

        vector<vector<int>> order_mirrored = mirror(order);
        for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            arr[order_mirrored[r][c]] = m[r][c];
        ans = max(ans, kadane(arr));

        order = rotate(order);
    }
    cout << ans << "\n";

    return 0;
}