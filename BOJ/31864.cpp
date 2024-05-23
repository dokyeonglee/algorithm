#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<pair<int, int>, vector<long long>> mp;

    for(int i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;
        int g = gcd(abs(x), abs(y));
        mp[make_pair(x / g, y / g)].push_back(x * x + y * y);
    }

    for(auto& it : mp){
        sort(it.second.begin(), it.second.end());
    }

    int answer = 0;

    for(int i = 0; i < m; i++){
        long long x, y;
        cin >> x >> y;
        int g = gcd(abs(x), abs(y));
        if(mp.count(make_pair(x / g, y / g))){
            auto& it = mp[make_pair(x / g, y / g)];
            auto it2 = upper_bound(it.begin(), it.end(), x * x + y * y);
            answer = max(answer, (int)(it2 - it.begin()));
        }
    }

    cout << answer;

    return 0;
}