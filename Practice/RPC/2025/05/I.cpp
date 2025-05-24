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

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    vector<int> mx(5, -1);
    int a = 0, b = 0, c = 0;
    while (n--) {
        int aux, higher = 0;
        for (int i = 0; i < 5; i++) {
            cin >> aux;
            if (aux > mx[i]) higher++;
            mx[i] = max(mx[i], aux);
        }

        if (higher == 3) a++;
        else if (higher == 4) b++;
        else if (higher == 5) c++;
    }
    cout << a << " " << b << " " << c << "\n";

    return 0;
}