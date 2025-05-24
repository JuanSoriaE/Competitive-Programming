#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    ll g, r;cin>>g>>r;
    ll res=0;
    ll pairs = min(g,r);
    res+=pairs*10;
    g-=pairs;
    r-=pairs;
    res+=(g/3)*10;
    g%=3;
    res+=(g/2)*3;
    g%=2;
    res+=g;
    cout<<res << "\n";

    return 0;
}