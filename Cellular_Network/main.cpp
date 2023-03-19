#include<iostream>

int main(){
    int n, m; std::cin >> n >> m;
    long a[n]; for(int i = 0; i < n; i++) std::cin >> a[i];
    long b[m]; for(int i = 0; i < m; i++) std::cin >> b[i];
    
    long max = 0;
    
    int city = 0, tower = 0;
    while (city < n && tower < m - 1) {
        if (std::abs(a[city] - b[tower]) >= std::abs(a[city] - b[tower + 1]) ) tower++;
        else {
            max = std::max(max, (long)abs(a[city] - b[tower]));
            city++;
        }
    }
    while(city < n) max = std::max(max, (long)abs(a[city] - b[tower])), city++;
    
    std::cout << max << std::endl;
            
}