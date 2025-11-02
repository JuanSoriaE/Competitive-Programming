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

#define MAX_H 2500
#define MAX_W 2500
char grid[MAX_H][MAX_W];
bool vst[MAX_H][MAX_W];
int h, w;

bool is_possible(int l) {
    for (int i = 0; i < h; i++)
    fill(vst[i], vst[i] + w, false);

    for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
        if (grid[i][j] == '.' || vst[i][j]) continue;

        for (int k = i; k < i + l; k++)
        for (int m = j; m < j + l; m++) {
            if (k >= h || m >= w || grid[k][m] == '.' || vst[k][m])
                return false;

            vst[k][m] = true;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> h >> w;
    int n = 0;
    for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == '#') n++;
    }

    for (int ans = min(h, w); ans > 0; ans--) {
        if (n % (ans * ans) || !is_possible(ans)) continue;
        cout << ans << '\n';
        break;
    }
    return 0;
}