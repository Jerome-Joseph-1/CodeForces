#include<iostream>

int main(){
    long n, t; std::cin>>n>>t;
    int a[n]; for(int i = 0; i < n; i++) std::cin >> a[i];
    
    int l = 0,r = 0, count = 0, sum = 0;
    while ( r < n ) {
        sum += a[r];
        while( sum > t ) sum -= a[l], l++;
        count = std::max(r - l + 1, count);
        r++;
    } 
    std::cout << count << std::endl;
}