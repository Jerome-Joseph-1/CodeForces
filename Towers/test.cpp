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
    
    std::cin >> temp;
    mp.erase(temp);
    

    for(auto it = mp.begin(); it != mp.end(); it++) std::cout << it->first << " " << it->second << std::endl;
}