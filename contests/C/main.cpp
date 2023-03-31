#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<string>

using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long prod[n];
    for(long long i = 0, a, b; i < n; i++) {
        cin >> a;
        cin >> b;
        prod[i] = a * b;
    }

    long long count = 0, i, gcd;
    // long long gcd = prod[0], r = 0;
    // while(r < n) {
    //     gcd = __gcd(gcd, prod[r]);
    //     cout << prod[r] << " " << gcd << "\n";
    //     if(gcd == 1) {
    //         gcd = prod[r];
    //         count++;
    //     }
    //     r++;
    // }
    // cout << count << "\n";
    for(i = 0; i < n - 1; i++) {
        gcd = __gcd(prod[i], prod[i+1]);
        int temp = i + 1;
        while(gcd > 1 && temp < n && gcd == __gcd(gcd, prod[temp])) {
            temp++;
        }
        if(temp != i + 1) i = temp - 1;
        if(temp > n) break;
        count++;
    }
    if(i == n - 1) ++count;
    cout << count << "\n";

}

int main(){
    long long t;
    cin >> t;
    while(t--) solve();
}