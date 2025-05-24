#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int(x.size()))
#define ll long long

const vector<string> dynamics = {"ppp", "pp", "p", "mp", "mf", "f", "ff", "fff"};

int index_of_dynamic(string d) {
    return find(dynamics.begin(), dynamics.end(), d) - dynamics.begin();
}

void print_data(vector<vector<int>> &data) {
    for (int i = 0; i < 8; i++) {
        cout << dynamics[i] << ": ";
        for (int j = 0; j < SZ(data[i]); j++)
        cout << data[i][j] << " ";
        cout <<  "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> power(n);
    for (int i = 0; i < n; i++)
        cin >> power[i];

    vector<pair<int, string>> dynamic(m);
    for (int i = 0; i < m; i++) {
        int index; string d; cin >> index >> d;

        dynamic[i] = {index - 1, d};
    }

    vector<vector<int>> data(8);
    int j = 0, d_index;
    for (int i = 0; i < n; i++) {
        if (i == dynamic[j].first)
            d_index = index_of_dynamic(dynamic[j++].second);

        data[d_index].push_back(power[i]);
    }

    for (int i = 0; i < 8; i++)
    sort(data[i].begin(), data[i].end());

    ll ans = 0;
    for (int i = 0; i < 8; i++)
    for (int j = i + 1; j < 8; j++) {
        int index_1 = 0, index_2 = 0;
        while (index_1 < SZ(data[i]) && index_2 < SZ(data[j])) {
            while (index_1 < SZ(data[i]) && data[i][index_1] < data[j][index_2])
                index_1++;
    
            ans += SZ(data[i]) - index_1;

            index_2++;
        }
    }

    cout << ans << "\n";

    return 0;
}