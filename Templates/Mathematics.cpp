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

// Basics

#define MOD 1000000007
// Binary Exponentiation | O(log(b))
ll bin_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// Divisors of number | O(sqrt(n))
vector<int> divisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (n / i != i)
                divisors.push_back(n / i);
        }
    }
    return divisors;
}

// Primes

// Check if a number is prime | O(sqrt(n))
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// Primes smaller or equal to n (Sieve) | O(nlog(log(n))) | Limit 10^7
vector<int> primes;
void compute_primes(int n) {
    vector<bool> seen(n + 1);
    primes.push_back(2);
    for (int i = 4; i <= n; i += 2) seen[i] = true;
    for (int i = 3; i <= n; i++) {
        if (!seen[i]) {
            primes.push_back(i);
            for (ll j = (ll)i * i; j <= n; j += 2 * i)
                seen[j] = true;
        }
    }
}

// Number of primes smaller or equal to n | O((n^(3/4))/ln(n)) | Limit 10^10
lli pi_0(lli N){
	int m = sqrt(N);
	vector<lli> lo(m+1), hi(m+1);
	auto at = [&](lli x) -> lli&{
		if(x <= m) return lo[x];
		else return hi[N / x];
	};
	vector<lli> values;
	for(int i = 1; i <= m; ++i){
		values.push_back(i);
		if(N / i != i) values.push_back(N / i);
	}
	sort(values.begin(), values.end(), greater<lli>());
	for(lli n : values){
		at(n) = n - 1;
	}
	for(lli p = 2; p <= m; ++p){
		if(at(p) == at(p - 1)) continue;
		for(lli n : values){
			if(n < p*p) break;
			at(n) = at(n) - (at(n / p) - at(p - 1));
		}
	}
	return at(N);
}

// Factorization of number | O(sqrt(n)) if n is prime
vector<pair<int, int>> factors(int n) {
    vector<pair<int, int>> factors;
    for (int p : primes) {
        if (n == 1) break;
        int e = 0;
        while (n % p == 0) {
            n /= p;
            e++;
        }
        if (e) factors.push_back({p, e});
    }
    if (n != 1) factors.push_back({n, 1});
    return factors;
}

// Linear Algebra

// Matrix Multiplication | O(R*C*c)
vector<vector<ll>> mult_mat(vector<vector<ll>> &m1, vector<vector<ll>> &m2) {
    int R = sz(m1), C = sz(m1[0]);
    int r = sz(m2), c = sz(m2[0]);
    if (C != r) return {};

    vector<vector<ll>> res(R, vector<ll>(c));
    for (int i = 0; i < R; i++)
    for (int j = 0; j < c; j++)
    for (int k = 0; k < C; k++)
        res[i][j] = (res[i][j] + (m1[i][k] * m2[k][j]) % MOD) % MOD;
    
    return res;
}

// Binary Exponentiation (Matrix) | O((N^3)log(b))
vector<vector<ll>> bin_pow(vector<vector<ll>> m, ll b) {
    int N = sz(m);
    vector<vector<ll>> res(N, vector<ll>(N));
    for (int i = 0; i < N; i++) res[i][i] = 1;
    
    while (b) {
        if (b & 1)
            res = mult_mat(res, m);
        m = mult_mat(m, m);
        b >>= 1;
    }
    return res;
}

// Rotates a matrix (clockwise) | O(N*M)
vector<vector<int>> rotate(vector<vector<int>> &m) {
    const int N = sz(m), M = sz(m[0]);
    vector<vector<int>> rotated(M, vector<int>(N));
    for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
        rotated[j][N - 1 - i] = m[i][j];
    return rotated;
}

// Iterate a matrix in spiral order | O(N*M)
const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<int> spiral(vector<vector<int>> &m) {
    const int N = sz(m), M = sz(m[0]);
    vector<int> res(N * M);
    int row = 0, col = 0, dir_idx = 0, l = 0, r = M - 1, t = 1, b = N - 1;
    for (int i = 0; i < N * M; i++) {
        res[i] = m[row][col];

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
    return res;
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < sz(m); i++) {
        for (int j = 0; j < sz(m[0]); j++)
        cout << m[i][j] << " ";
        cout << endl;
    }

    for (auto i : spiral(m)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}