#include<iostream>
#include<set>

int main(){
    long n, a, b, count = 0;
    long long d, temp, x, y, prefix = 0;
    std::string ans = "";

    std::cin >> n >> d >> a >> b;

    std::multiset<std::pair<long long, long>> min_heap;

    for(long i = 0; i < n; i++) {
        std::cin >> x >> y;
        temp = x * a + y * b;
        min_heap.insert(std::make_pair(temp, i + 1));
    }

    for(auto it: min_heap) {
        prefix += it.first;
        if(prefix <= d) count++, ans += std::to_string(it.second) + " ";
    }

    if(count) std::cout << count << std::endl << ans << std::endl;
    else std::cout << 0 << std::endl;
}