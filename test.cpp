#include <iostream>
#include <map>

std::string solve(){
    long long n, m; std::cin >> n >> m;
    std::string a, b;
    std::cin >> a >> b;
    
    std::map<char, long long> map_a, map_b;
    for(long long i = 0; i < n; i++) {
        map_a[a[i]]++;
    }
    
    for(long long i = 0; i < m; i++) {
        map_b[b[i]]++;
    }
    
    long long odds = 0;
    
    if(m < n) {
        for(long long i = 0; i < m ; i++) {
            map_a[b[i]] -= map_b[b[i]];
            map_b[b[i]] = 0;
            if(map_a[b[i]] < 0) return "NO";
        }
        
        for(long long i = 0; i < n ; i++) {
            odds += 1 & map_a[a[i]];
            if(odds > 1) return "NO";
        }
    }
    else {
        for(long long i = 0; i < n ; i++) {
            map_b[a[i]] -= map_a[a[i]];
            map_a[a[i]] = 0;
            if(map_b[a[i]] < 0) return "NO";
        }
        
        for(long long i = 0; i < m ; i++) {
            odds += 1 & map_b[b[i]];
            if(odds > 1) return "NO";
        }
        
    }
    
    return "YES";
}

int main() {
    int t;
    std::cin >> t;
    while(t--) std::cout << solve() << std::endl;
	return 0;
}
