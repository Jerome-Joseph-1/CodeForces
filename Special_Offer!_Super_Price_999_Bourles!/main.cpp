#include<iostream>


int main(){
    long long p, d;
    std::cin >> p >> d;
    long long ans = p, temp = p, change_index = 10;

    while( temp >= change_index ) {
        if( (temp % change_index * 10) / (change_index) != 9) { 
            temp = temp +  (9 - (temp % change_index * 10) / (change_index)) * change_index / 10; 
            temp = temp - change_index;
        }
        change_index *= 10;
        if( p - temp <= d ) ans = temp;
    } 
    std::cout << ans << std::endl;
}