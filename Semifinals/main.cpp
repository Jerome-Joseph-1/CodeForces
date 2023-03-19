#include<iostream>
#include<set>

int main(){
    // auto cmp = [](std::pair<long long, long> a, std::pair<long long, long> b){
    //     return a.first < b.first;
    // };

    long n; std::cin >> n;
    long long a[2*n] = {};

    // std::multiset<std::pair<long long, long>, decltype(cmp)> min_heap(cmp);    

    for(long i = 0; i < n; i++) {
        std::cin >> a[i] >> a[i+n];

        // min_heap.insert(std::make_pair(a[i], i));
        // min_heap.insert(std::make_pair(a[i+n], i + n));
    }

    long l = 0, r = n, i = 1;
    std::string ans1(n, '0'), ans2(n, '0');

    // std::cout << ans1 << std::endl;
    // while(l <= n/2 && )
    while(2*i <= n) {
        ans1[i - 1] = ans2[i - 1] = '1';
        i++;
    }

    for(long i = 0; i < n; i++) {
        if(a[l] > a[r]) ans2[r - n] = '1',r++;
        else ans1[l] = '1', l++;
    }

    std::cout << ans1 << "\n" << ans2 << std::endl;
} 