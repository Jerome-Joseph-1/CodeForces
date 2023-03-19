#include<iostream>

bool check (long a, long b, long c);
bool check (long a, long b, long c, long d);

void solve() {
    int n; std::cin >> n;
    long a[n]; for(int i = 0; i < n; i++) std::cin >> a[i];
    
    long long count = 0;
    
    for(int i = 0; i < n - 2; i++) {
        if ( check(a[i], a[i+1], a[i+2]) ) {
            count++;
            if( i + 3 < n && check(a[i], a[i+1], a[i+2], a[i+3]) ) count++; 
        }
    }
    
    std::cout << count + 2*n - 1 << std::endl;
}

int main(){
    int t; std::cin >> t; while (t--) 
    solve();
}

bool check (long a, long b, long c) {
    if((b > a && b > c) || (b < a && b < c)) {
        return true;
    }
    return false;
}

bool check (long a, long b, long c, long d) {
    // long max = std::max(a, std::max(b, c));
    // long min = std::min(a, std::min(b, c));
    // long mid = a + b + c - max - min;
    if ( check(a, b, d) && check(a,c,d) && check(b, c, d) ) return true;
    return false;   
}