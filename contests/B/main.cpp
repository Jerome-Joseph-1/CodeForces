#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<string>

using namespace std;

void solve(){
    long long m;
    cin >> m;
    vector<vector<long long>> participants(m);
    map<long long, long long> count;

    for(long long i = 0, n; i < m; i++) {
        cin >> n;
        for(long long j = 0, temp; j < n; j++) {
            cin >> temp;
            participants[i].push_back(temp);
            count[temp] += 1;
        }
    }
    string ans = "";
    bool flag = false;
    for(long long i = 0; i < m; i++) {
        for(long long j = 0; j < participants[i].size(); j++) {
                // cout << participants[i][j] << " ";
            if( count[participants[i][j]] == 1 ) {
                if(!flag){
                    ans += to_string(participants[i][j]);
                    ans += " ";
                }
                flag = true;
            }
            count[participants[i][j]] -= 1;
        }
        // cout << "\n";
        if(!flag) {
            cout << "-1\n";
            return;
        }
        flag = false;
    }
    cout << ans << "\n";
}

int main(){
    long long t;
    cin >> t;
    while(t--) solve();
}