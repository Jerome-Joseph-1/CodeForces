#include<iostream>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n], b[n];

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = n - 2; i > -1; i--) {
        if((a[i] > a[n - 1] && (b[i] > a[n-1] || a[i] > b[n-1])) || (b[i] > b[n-1] && (a[i] > b[n-1] || b[i] > a[n-1]))) {
            cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
}

int main(){
    long long t;
    cin >> t;
    while(t--) solve();
}