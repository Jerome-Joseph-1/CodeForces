#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    auto cmp = [](ll &a, ll &b){
        return a > b;
    };
    
    ll n, k, blocks = 0, sweeps = 0; cin >> n >> k;
    ll a[n]; for(ll i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a+n, cmp);
    for(ll i = 0; i < n-1; i++){
        if(a[i] == a[i+1]) continue;
        if(blocks && blocks + (a[i] - a[i+1])*(i+1) > k){
            sweeps++;
            a[i] -= (k - blocks)/(i+1);
            blocks = 0;
        }
        
        if((a[i] - a[i+1])*(i+1) > k){
            ll rowsRemoved = (a[i] - a[i+1]) / (k/(i+1));
            sweeps += rowsRemoved;
            a[i] -= rowsRemoved * (k/(i+1));
            blocks = 0;
        }
        
        blocks += (a[i] - a[i+1]) * (i+1);
    }
    if(blocks) sweeps++;
    cout << sweeps << endl;
}

int main(){
    // int t; cin >> t; while( t-- )
    solve();
}