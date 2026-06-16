#include <bits/stdc++.h>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << x << "\n";
#define PI acos(-1)
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double

#define MAX_N 100
#define MAX_B 60

const int ALL_BITS = (1 << 17) - 1;

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int factors_set(int n) {
    int factors_set = 0;
    for (int i = 0; i < 17; i++)
    if (n % primes[i] == 0) factors_set |= (1 << i);
    return factors_set;
}

int a[MAX_N + 1], ans[MAX_N + 1];
// ans, b, from
array<int, 3> dp[MAX_N + 1][1 << 17];
int factors[MAX_B];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fill(dp[i], dp[i] + (1 << 17), array<int, 3>{INT_MAX, 0, 0});
    }
    fill(dp[0], dp[0] + (1 << 17), array<int, 3>{0, 0, 0});

    for (int i = 1; i < MAX_B; i++)
        factors[i] = factors_set(i);

    for (int i = 1; i <= n; i++)
    for (int b = 1; b < 2 * a[i]; b++) {
        int b_set = factors_set(b);
        int superset = ALL_BITS & (~b_set);

        for (int subset = superset; ; subset = (subset - 1) & superset) {
            if (dp[i - 1][subset][0] + abs(a[i] - b) < dp[i][subset | b_set][0]) {
                dp[i][subset | b_set][0] = dp[i - 1][subset][0] + abs(a[i] - b);
                dp[i][subset | b_set][1] = b;
                dp[i][subset | b_set][2] = subset;
            }
            if (subset == 0) break;
        }
    }

    int ans_subset = min_element(dp[n], dp[n] + (1 << 17)) - dp[n];
    for (int i = n; i > 0; i--) {
        ans[i] = dp[i][ans_subset][1];
        ans_subset = dp[i][ans_subset][2];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}