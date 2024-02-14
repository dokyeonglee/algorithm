#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return (a.second.first + a.second.second) < (b.second.first + b.second.second);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> arr(n);
    for(auto& a : arr){
        cin >> a.second.first >> a.second.second >> a.first;
        a.second.second--;
        a.second.first--;
    }

    arr.emplace_back(0, make_pair(0, 0));
    arr.emplace_back(0, make_pair(r - 1, c - 1));

    sort(arr.begin(), arr.end(), compare);

    int left = 1;
    int right = r + c;

    int answer = right;

    while(left <= right){
        int mid = (left + right) / 2;
        vector<int> dp(n + 2, -1);
        dp[0] = mid;
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < i; j++){
                if(arr[j].second.first <= arr[i].second.first and arr[j].second.second <= arr[i].second.second){
                    int dist = arr[i].second.first - arr[j].second.first + arr[i].second.second - arr[j].second.second;
                    if(dist <= dp[j]){
                       dp[i] = max(dp[i], dp[j] - dist + arr[i].first);
                    }
                }
            }
        }
        if(dp.back() != -1){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}