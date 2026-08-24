#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << '\n';
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

const vector<vector<string>> aux = {
    {
        "00",
        "00"
    },
    {
        "10",
        "00"
    },
    {
        "01",
        "00"
    },
    {
        "00",
        "10"
    },
    {
        "00",
        "01"
    },
    {
        "11",
        "00"
    },
    {
        "00",
        "11"
    },
    {
        "10",
        "10"
    },
    {
        "01",
        "01"
    },
    {
        "10",
        "01"
    },
    {
        "01",
        "10"
    },
    {
        "01",
        "11"
    },
    {
        "10",
        "11"
    },
    {
        "11",
        "01"
    },
    {
        "11",
        "10"
    },
    {
        "11",
        "11"
    },
};

const vector<vector<vector<int>>> res = {
    {},
    {
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 1}
    },
    {
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1}
    },
    {
        {0, 0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0},
    },
    {
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 1}
    },
    {
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 0, 1, 1}
    },
    {
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 0}
    },
    {
        {0, 0, 0, 1, 1, 1},
        {0, 1, 1, 0, 1, 1}
    },
    {
        {0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 1}
    },
    {
        {0, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1}
    },
    {
        {0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 1}
    },
    {
        {0, 1, 1, 0, 1, 1}
    },
    {
        {0, 0, 1, 0, 1, 1}
    },
    {
        {0, 0, 0, 1, 1, 1}
    },
    {
        {0, 0, 0, 1, 1 ,0}
    },
    {
        {0, 0, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1}
    }
};



void solve() {
    int n, m; cin >> n >> m;
    vector<string> mat(n);
    for (auto &s : mat) cin >> s;

    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < m - 1; j++) {
        if (mat[i][j] == '0' && mat[i][j + 1] == '0') continue;

        if (mat[i][j] == '1' && mat[i][j + 1] == '1') {
            ans.push_back({i, j, i, j + 1, i + 1, j});
            mat[i][j] = (mat[i][j] == '0' ? '1' : '0');
            mat[i][j + 1] = (mat[i][j + 1] == '0' ? '1' : '0');
            mat[i + 1][j] = (mat[i + 1][j] == '0' ? '1' : '0');
        } else if (mat[i][j] == '1') {
            ans.push_back({i, j, i + 1, j, i + 1, j + 1});
            mat[i][j] = (mat[i][j] == '0' ? '1' : '0');
            mat[i + 1][j] = (mat[i + 1][j] == '0' ? '1' : '0');
            mat[i + 1][j + 1] = (mat[i + 1][j + 1] == '0' ? '1' : '0');
        } else {
            ans.push_back({i, j + 1, i + 1, j, i + 1, j + 1});
            mat[i][j + 1] = (mat[i][j + 1] == '0' ? '1' : '0');
            mat[i + 1][j] = (mat[i + 1][j] == '0' ? '1' : '0');
            mat[i + 1][j + 1] = (mat[i + 1][j + 1] == '0' ? '1' : '0');
        }
    }

    for (int i = 0; i < m - 2; i++) {
        if (mat[n - 2][i] == '0' && mat[n - 1][i] == '0') continue;

        if (mat[n - 2][i] == '1' && mat[n - 1][i] == '1') {
            ans.push_back({n - 2, i, n - 1, i, n - 1, i + 1});
            mat[n - 2][i] = (mat[n - 2][i] == '0' ? '1' : '0');
            mat[n - 1][i] = (mat[n - 1][i] == '0' ? '1' : '0');
            mat[n - 1][i + 1] = (mat[n - 1][i + 1] == '0' ? '1' : '0');
        } else if (mat[n - 2][i] == '1') {
            ans.push_back({n - 2, i, n - 2, i + 1, n - 1, i + 1});
            mat[n - 2][i] = (mat[n - 2][i] == '0' ? '1' : '0');
            mat[n - 2][i + 1] = (mat[n - 2][i + 1] == '0' ? '1' : '0');
            mat[n - 1][i + 1] = (mat[n - 1][i + 1] == '0' ? '1' : '0');
        } else {
            ans.push_back({n - 1, i, n - 2, i + 1, n - 1, i + 1});
            mat[n - 1][i] = (mat[n - 1][i] == '0' ? '1' : '0');
            mat[n - 2][i + 1] = (mat[n - 2][i + 1] == '0' ? '1' : '0');
            mat[n - 1][i + 1] = (mat[n - 1][i + 1] == '0' ? '1' : '0');
        }
    }

    vector<string> tmp = {
        mat[n - 2].substr(m - 2, 2),
        mat[n - 1].substr(m - 2, 2)
    };
    int j;
    for (int i = 0; i < 16; i++) {
        if (aux[i] == tmp) j = i;
    }

    vector<vector<int>> x = res[j];
    for (auto &v : x) {
        for (int i = 0; i < 6; i++)
            if (i % 2 == 0) v[i] += n - 2;
            else v[i] += m - 2;
        ans.push_back(v);
    }

    cout << sz(ans) << '\n';
    for (auto &v : ans) {
        for (int &i : v) cout << i + 1 << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}