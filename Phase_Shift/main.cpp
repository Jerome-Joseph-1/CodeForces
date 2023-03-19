#include<iostream>
#include<map>

auto to_char = [](int number) {
    return (char)(97 + number);
};

auto to_int = [](char c) {
    return (int)(c - 97);
};

bool loop(char parent, char child, std::map<char, char>& parent_array){
    while(parent) {
        if(child == parent) return true;
        parent = parent_array[parent];
    }
    return false;
}

void solve() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    char map[26] = {};
    std::map<char, char> parent;
    std::map<char, bool> used;
    int mapping = 0, filled = 0;

    for(int i = 0; i < n; i++) {
        if(map[to_int(s[i])]) {
            s[i] = map[to_int(s[i])];
        } 
        else {
            int cur_map = mapping;
            while ( filled < 25 && (used[to_char(cur_map)] || to_char(cur_map) == s[i] || loop(s[i], to_char(cur_map), parent)) ) {
                cur_map = ( 1 + cur_map ) % 26;
            }
            filled++;
            parent[to_char(cur_map)] = s[i];
            used[to_char(cur_map)] = true;
            if(filled < 26) while(used[to_char(mapping)]) mapping = (1 + mapping) % 26;
            map[to_int(s[i])] = to_char(cur_map); 
            s[i] = to_char(cur_map);
        }
    // std::cout << s << std::endl;
    }
    std::cout << s << std::endl;
}

int main(){
    int t; std::cin >> t;
    while(t--) {
        solve();
    }
}

// 