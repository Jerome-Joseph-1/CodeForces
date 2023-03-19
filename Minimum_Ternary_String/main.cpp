#include<iostream>

int main(){
    std::string s; std::cin >> s;
    std::string ones = "";
    std::string ans = "";
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1') ones += '1';
    }
    
    int i = 0;
    while(i < s.length()) {
        if(s[i] == '2') break;
        else if(s[i] == '0') ans += '0';

        i++;
    }
    ans += ones;
    while(i < s.length()) {
        if(s[i] != '1')
            ans += s[i];
        i++;
    }
    
    std::cout << ans << std::endl;
}