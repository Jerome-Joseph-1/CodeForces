#include<iostream>
#include<set>

int main(){
    auto cmp = [](std::pair<long long, int> a, std::pair<long long, int> b){
        if(a.first > b.first) return false;
        return true;
    };

    int n, k;
    std::cin >> n >> k;
    
    std::multiset<std::pair<long long, int>, decltype(cmp)> mp(cmp);
    long long temp;
    for(int i = 0; i < n; i++) {
        std::cin >> temp;
        mp.insert(std::make_pair(temp, i));
    }
    
    std::string ans = "\n";
    long long m = 0;


    while(k--) {
        auto high_pair = mp.rbegin();
        auto low_pair = mp.begin();
        
        long long high = high_pair->first;
        long long low = low_pair->first;

        if(high == low) break;

        ans += std::to_string(high_pair->second + 1) + " " + std::to_string(low_pair->second + 1) + "\n";

        auto new_h_pair = std::make_pair(high - 1, high_pair->second);
        auto new_l_pair = std::make_pair(low + 1, low_pair->second);

        mp.erase(mp.begin());
        mp.erase(--mp.end());

        mp.insert(new_h_pair);
        mp.insert(new_l_pair);

        m++;
    }
    long long lowest = mp.rbegin()->first - mp.begin()->first;
    std::cout << lowest << " " << m << ans;
}