#include<bits/stdc++.h>
#define debug() cerr<<"#x:"<<x<<endl

using namespace std;

void solve(){
    int n,x; cin>>n>>x;

    vector<int> grado(n+1,0);
    for(int i=1; i<n; i++){
        int a,b;
        cin >> a >> b;
        grado[a]++;
        grado[b]++;
    }
    if(grado[x]==1 || n%2==0 || n == 1){  
        cout<<"Ayush"<<endl;
    }else{
        cout<<"Ashish"<<endl;
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}