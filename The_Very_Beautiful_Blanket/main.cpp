#include<iostream>

int log_2(int num) {
    int count = 0;
    while(num) num>>=1, ++count;
    return count;
}

void solve(){
    int n, m;
    std::cin >> n >> m;
    
    int matrix[n][m];
    
    int num = 1 << (log_2(n) + 1);
    
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            matrix[i][j] = num * j + i + 1;
        }
    }
    std::cout << n * m << "\n";
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            std::cout << matrix[j][i] << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    int t;
    std::cin >> t;
    while(t--) 
        solve();
}