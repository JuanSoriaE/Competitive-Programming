#include<bits/stdc++.h>
#include<random>
#define ld long double
#define ff first
#define pb push_back 
#define ss second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define MAT vector<vll>
#define MAX 1000005
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define MOD 1000000007

using namespace std;

struct Edge {
    int w, u, v;
    Edge(int w, int u, int v) : w(w), u(u), v(v){}
    bool operator<(const Edge& x) const {
        return w < x.w;
    }
};
struct DSU{
    int n;
    vi p, sz;
    DSU(int n) : n(n), p(n), sz(n, 1){
        iota(all(p), 0);
    }
    int find(int v){
        return (p[v] == v ? v : p[v] = find(p[v]));
    }
    void unite(int u, int v){
        u = find(u), v = find(v);
        if(u != v){
            if(sz[u] > sz[v]) swap(u, v);
            p[u] = v;
            sz[v] += sz[u];
        }
    }
    bool same(int u, int v){
        return find(u) == find(v);
    }
};
void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> e;
    for(int i = 1; i <= n; ++i){
        int w; cin >> w;
        e.pb(Edge(w, i, 0));
    }
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        e.pb(Edge(w, u , v));
    }
    sort(all(e));
    ll ans = 0;
    DSU dsu(n + 1);
    for(auto x : e){
        if(!dsu.same(x.u, x.v)){
            dsu.unite(x.u,x.v);
            ans += x.w;
        }
    }
    cout << ans << "\n";
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1; // cin >> t; 
    while(t--) solve();
    return 0;
}