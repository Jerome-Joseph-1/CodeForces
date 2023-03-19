#include<iostream>
#include<map>

void solve(){
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::map<char, long long> mp1, mp2;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(mp1[s[i]] == 0) ans++;
        mp1[s[i]]++;
    }
    long long a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        mp1[s[i]]--;
        if(mp1[s[i]] < 0) mp1[s[i]] = 0;
        mp2[s[i]]++;
        a = 0;
        b = 0;
        for(int c = 0; c < 26; c++) {
            if(mp1[(char)('a' + c)]) a++;
            if(mp2[(char)('a' + c)]) b++;
        }
        ans = std::max(ans, a+b);
    }
    std::cout << ans << std::endl;
}

int main(){
    int t; std::cin >> t;
    while(t--) solve();
}