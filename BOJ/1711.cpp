#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    int answer = 0;

    for(int i = 0; i < n; i++){
        map<pair<long long, long long>, int> mp;
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            long long x = arr[i].first - arr[j].first;
            long long y = arr[i].second - arr[j].second;
            long long g = gcd(abs(x), abs(y));
            x /= g;
            y /= g;
            mp[make_pair(x, y)]++;
        }
        for(auto& it : mp){
            if(mp.count(make_pair(it.first.second, -it.first.first))){
                answer += it.second * mp[make_pair(it.first.second, -it.first.first)];
            }
        }
    }

    cout << answer;

    return 0;
}