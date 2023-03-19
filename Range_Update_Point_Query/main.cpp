#include<iostream>
#include<vector>
#include<set>

long long compute(long long val) {
    long long ans = 0;
    while(val) ans += val % 10, val /= 10;
    return ans;
}

void solve(){
    long n, q, l, r, x;
    int choice;
    std::cin >> n >> q;
    
    std::vector<long long> a(n + 1);
    std::set<long> indices;
    
    for(long i = 0; i < n; i++) {
        std::cin >> a[i + 1];
        indices.insert(i + 1);
    }
    
    while(q--) {
       std::cin >> choice;
       
       if(choice == 1) {
            std::cin >> l >> r;

            auto findi = indices.lower_bound(l);
            std::vector<long> for_delete;
            for(; findi!= indices.end() && *findi <= r; findi++) {
                // std::cout << *findi << " " << a[*findi] << "\n";
                
                a[*findi] = compute(a[*findi]);
                if( a[*findi] / 10 == 0){
                    for_delete.push_back(*findi);
                }
            }

            for(auto it: for_delete) indices.erase(indices.find(it));
       } else {
           std::cin >> x;
           std::cout << a[x] << "\n";
       }
    }
}

int main(){
    int t;
    std::cin >> t;
    while(t--) solve();
}