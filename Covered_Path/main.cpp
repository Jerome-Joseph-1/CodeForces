#include<iostream>

int main(){
    int v1, v2, t, d;
    std::cin >> v1 >> v2 >> t >> d;
    
    int a[t], l = 0, r = t - 1;
    a[0] = v1;
    a[t-1] = v2;
    if(a[t - 1] > a[0]) while(a[r] - v1 > d) --r, a[r] =  std::max(v1 + d, a[r+1] - d);
    else if(a[0] > a[t-1]) while(a[l] - v2 > d) ++l, a[l] =  std::max(a[l-1] - d, v2 + d);
    l++; r--;
    while(l < r) {
        a[l] = a[l-1] + d;
        a[r] = a[r+1] + d;
        l++;
        r--;
    }
    
    if(l == r) a[l] = std::min(a[l-1], a[l+1]) + d;
    
    long long sum = 0;
    for(int i = 0; i < t; i++) {
        // std::cout << a[i] << " ";
        sum += a[i];
    }
    std::cout << sum << "\n";
}