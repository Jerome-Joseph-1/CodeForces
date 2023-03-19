#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

void solve(){
    auto cmp = [](std::pair<long long, long long> left, std::pair<long long, long long> right){
        return left.second < right.second;
    };
    
    long long n, c, count = 0;
    
    std::cin >> n >> c;
    std::vector<bool> v(n);
    
    std::set<std::pair<long long, long long>, decltype(cmp)> a(cmp), b(cmp);
    
    for(long long i = 0, temp; i < n; i++) {
        std::cin >> temp;
        a.insert(std::make_pair(i, temp + i + 1));
        b.insert(std::make_pair(i, temp + (n - i)));
    }
    
    while(!(a.empty() || b.empty())) {
        long long ind1 = n+1, ind2 = n+1;
        long long val1, val2;
        
        while(!a.empty()){
            auto cmp1 = a.begin();
            if(v[cmp1->first]) a.erase(a.begin());
            else{
                ind1 = cmp1->first;
                val1 = cmp1->second;
                break;
            };
        }

        while(!b.empty()){
            auto cmp2 = b.begin();
            if(v[cmp2->first]) b.erase(b.begin());
            else{
                ind2 = cmp2->first;
                val2 = cmp2->second;
                break;
            };
        }

        if(ind1 == n + 1 || ind2 == n + 1) break;
        v[ind1] = v[ind2] = 1;
        if(val1 > val2) {
            if(c - val2 < 0) break;
            c -= val2;
            b.erase(b.find(std::make_pair(ind2, val2)));
        }
        else {
            if(c - val1 < 0) break;
            c -= val1;
            a.erase(a.find(std::make_pair(ind1, val1)));
        }
        count++;
    }

    std::cout << count << "\n";
}

int main(){
    int t;
    std::cin >> t;
    while(t--) solve();
}