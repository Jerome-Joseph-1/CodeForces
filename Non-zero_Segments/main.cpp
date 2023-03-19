#include<iostream>
#include<set>

int main(){
    int n; 
    std::cin >> n;
    long long a[n];
    long long count = 0;
    for(int i = 0; i < n; i++) std::cin >> a[i];
    
    std::set<long long> prefix;

    prefix.insert(0);
    long long sum = 0;

    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(prefix.find(sum) != prefix.end()) {
            prefix.clear();
            prefix.insert(0);
            count++;
            sum = a[i];
        }
        prefix.insert(sum);
    }

    std::cout << count << std::endl;
}

/*
100
2 1 -2 -1 -2 -1 -2 1 2 1 -2 -1 -2 2 1 -2 -2 2 -2 2 -2 2 2 -1 -2 2 -1 -1 -2 -1 -2 2 -2 -2 -2 -1 1 -2 -1 2 -1 -2 1 -1 1 1 2 -2 1 -2 1 2 2 -2 1 -2 -1 -1 -2 -2 1 -1 -1 2 2 -1 2 1 -1 2 2 1 1 1 -1 -1 1 -2 -2 2 -1 2 -2 2 -2 -1 -2 -2 -1 -1 2 -2 -2 1 1 -2 -1 -2 -2 2

1
*/