#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    auto cmp = [](pair<ll, ll> const &a, pair<ll, ll> const &b){
            return a.first <= b.first;
        };

        ll n, count = 0; cin >> n;
        multiset<pair<ll, ll>, decltype(cmp)> mp(cmp);
        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            if(temp > 0)mp.insert(make_pair(temp, i+1));
        }
        vector<pair<ll, ll>> ans;
        while(mp.size() > 1){
            
            pair<ll, ll> a = *mp.rbegin();
            mp.erase(--mp.end());
            pair<ll, ll> b = *mp.rbegin();
            mp.erase(--mp.end());
            ans.push_back(make_pair(a.second , b.second));
            if(a.first > 1) mp.insert(make_pair(a.first - 1, a.second));
            if(b.first > 1) mp.insert(make_pair(b.first - 1, b.second));
        }
        cout << ans.size() << endl;
        for(auto it: ans) cout << it.first << " " << it.second << endl;
}

int main(){
    ll t; cin >> t;
    while(t--){
        solve();
    }
}