#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n]; for(long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    // for(auto i: a) cout << i << " ";
    // cout << endl;
    ll prefix[n] = {a[0]}; for(long long i = 1; i < n; i++) prefix[i] = prefix[i-1] + a[i];
    // for (auto i: prefix) cout << i << " ";
    // cout << endl;
    // choose x and y 
    long long ans = a[0] + n - 1; // 7
    // cout << "j top top/j+1 x" << endl;
    for(long long j = 0; j < n; j++) {
        long long top = k - prefix[n - j - 1] + a[0];

        double val = (double)top / (j+1);
        if(top < 0) val = -1 * ceil(-1 * val);
        val = floor(val);

        long long x = a[0] - val; 
        ans = min(ans, max(x,  0ll) + j);
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}