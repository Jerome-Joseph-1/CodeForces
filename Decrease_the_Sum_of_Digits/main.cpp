// link-->https://codeforces.com/problemset/problem/1409/D

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    vector<ll> a;
    string n;
    ll s, sum = 0;
    cin >> n >> s;
    for(ll i = 0; i < n.length(); i++) a.push_back(n[i] - '0'), sum += a[i];

    if(sum <= s) cout << 0 << endl;
    else {
        ll toadd = 0, carry = 0 ,i = n.length() - 1;
        string result = "";
        for(; i >= 0; i--){
            a[i] += carry;
            carry = (a[i])/10;
            if(a[i]%10){
                toadd = 10 - a[i]%10;
                carry = 1;
            } else {
                toadd = 0;
            }
            sum = sum - a[i] + 1;
            result = to_string(toadd) + result;
            if(sum <= s) break;
        }
        cout << result << endl;
    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}