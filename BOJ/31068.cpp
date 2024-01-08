#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    sort(arr.begin(), arr.end());

    vector<int> same_grade_cnt;
    vector<pair<int, int>> _same_grade_cnt;
    _same_grade_cnt.emplace_back(arr[0].second, 1);

    int x = arr[0].second;

    for(int i = 1; i < n; i++){
        x = max(x, arr[i].second);
        if(arr[i].first == arr[i - 1].first){
            _same_grade_cnt.back().first = x;
            _same_grade_cnt.back().second++;
            continue;
        }
        int cnt = 1;
        while(!_same_grade_cnt.empty() and _same_grade_cnt.back().first >= arr[i].second){
            cnt += _same_grade_cnt.back().second;
            _same_grade_cnt.pop_back();
        }
        _same_grade_cnt.emplace_back(x, cnt);
    }

    for(int i = 0; i < _same_grade_cnt.size(); i++){
        same_grade_cnt.push_back(_same_grade_cnt[i].second);
    }

    if(same_grade_cnt.size() < 3){
        cout << -1;
        return 0;
    }
 
    for(int i = 1; i < same_grade_cnt.size(); i++){
        same_grade_cnt[i] += same_grade_cnt[i - 1];
    }

    int answer = 987654321;

    for(int i = 0; i < same_grade_cnt.size() - 2; i++){

        int x = same_grade_cnt[i];
        auto it = lower_bound(same_grade_cnt.begin(), same_grade_cnt.end(), x + (same_grade_cnt.back() - x) / 2) - same_grade_cnt.begin();
        
        if(it - 1 < same_grade_cnt.size() - 1 and it - 1 > i){
            int y = same_grade_cnt[it - 1] - x;
            int z = same_grade_cnt.back() - y - x;
            answer = min(answer, max(x, max(y, z)) - min(x, min(y, z)));
        }
        if(it < same_grade_cnt.size() - 1){
            int y = same_grade_cnt[it] - x;
            int z = same_grade_cnt.back() - y - x;
            answer = min(answer, max(x, max(y, z)) - min(x, min(y, z)));
        }
        if(it + 1 < same_grade_cnt.size() - 1){
            int y = same_grade_cnt[it + 1] - x;
            int z = same_grade_cnt.back() - y - x;
            answer = min(answer, max(x, max(y, z)) - min(x, min(y, z)));
        }

    }

    if(answer == 987654321){
        answer = -1;
    }

    cout << answer;

    return 0;
}