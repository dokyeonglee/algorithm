#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> N(7);
    for(auto& n : N){
        cin >> n;
    }

    vector<int> T(7);
    for(auto& t : T){
        cin >> t;
    }

    vector<pair<int, int>> zzz;

    for(int i = 0; i < 7; i++){
        vector<pair<int, int>> arr(N[i]);
        for(auto& a : arr){
            cin >> a.first >> a.second;
        }
        sort(arr.begin(), arr.end());
        int now = 0;
        for(auto& a : arr){
            if(now < a.first){
                zzz.emplace_back(now, a.first);
                now = a.second;
            }else{
                now = max(now, a.second);
            }
        }
        zzz.emplace_back(now, T[i]);
    }

    sort(zzz.begin(), zzz.end());

    zzz.erase(unique(zzz.begin(), zzz.end()), zzz.end());    

    long long answer = 0;

    int left = zzz[0].first;
    int right = zzz[0].second;

    for(int i = 1; i < zzz.size(); i++){
        if(right < zzz[i].first){
            answer += right - left;
            left = zzz[i].first;
            right = zzz[i].second;
        }else{
            right = max(right, zzz[i].second);
        }
    }

    answer += right - left;

    cout << answer;

    return 0;
}