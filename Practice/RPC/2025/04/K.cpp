#include <bits/stdc++.h>
using namespace std;
#define SZ(x) (int(x.size()))

void print_m(vector<vector<int>> &m) { for (int i = 0; i < SZ(m); i++) { for(int j = 0; j < SZ(m[0]); j++) cout << m[i][j] << " "; cout << "\n"; } };

vector<vector<int>> rotate_90(vector<vector<int>> &m) {
    const int N = SZ(m), M = SZ(m[0]);

    vector<vector<int>> rotated(M, vector<int>(N));

    for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
        rotated[j][N - 1 - i] = m[i][j];

    return rotated;
}

int sum_blocked_trees(vector<vector<int>> &lot, vector<vector<char>> &building, int x, int y) {
    int sum = 0;
    for (int i = 0; i < SZ(building); i++)
    for (int j = 0; j < SZ(building[0]); j++)
        sum += (building[i][j] == '#' ? lot[y + i][x + j] : 0);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int r, c; cin >> r >> c;
    vector<vector<int>> lot(r, vector<int>(c));
    int sum_trees = 0;
    for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
        cin >> lot[i][j];
        sum_trees += lot[i][j];
    }

    int s, t; cin >> s >> t;
    vector<vector<char>> building(s, vector<char>(t));
    for (int i = 0; i < s; i++)
    for (int j = 0; j < t; j++)
        cin >> building[i][j];

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int y = 0; y < r - s + 1; y++)
        for (int x = 0; x < c - t + 1; x++)
            ans = max(ans, sum_trees - sum_blocked_trees(lot, building, x, y));

        swap(r, c);
        lot = rotate_90(lot);
    }

    cout << ans << "\n";

    return 0;
}