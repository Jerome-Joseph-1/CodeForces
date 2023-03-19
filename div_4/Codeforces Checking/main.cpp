#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n, m, c;
    cin >> n >> m >> c;

    long long a[n], b[m];

    for(long long i = 0;i < n; i++) cin >> a[i];

    for(long long i = 0; i < m; i++)  cin >> b[i];

    long long r_sum = 0, l = 0, r = -1;
    for(long long i = 0; i < n; i++) {
        // r = min(r+1, m-1);
        if( r + 1 < m ) r_sum += b[++r];
        if( i >= n - m + 1 ) {
            r_sum -= b[l];
            l++;
        }
        a[i] = ( a[i] + r_sum ) % c;
    }
    for(long long i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    // int t; cin >> t; while(t--)
    solve();
}