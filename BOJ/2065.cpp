#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, t, n;
    cin >> m >> t >> n;

    vector<pair<int, int>> left;
    vector<pair<int, int>> right;

    for(int i = 0; i < n; i++){
        int t;
        string str;
        cin >> t >> str;
        if(str[0] == 'l'){
            left.push_back(make_pair(t, i));
        }else{
            right.push_back(make_pair(t, i));
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    vector<int> answer(n);

    int time = 0;
    int idx = 0;
    int idx2 = 0;
    int direction = 0;
    int passanger_cnt = 0;

    while(idx < left.size() and idx2 < right.size()){
        if(direction == 0){
            if(left[idx].first > right[idx2].first){
                time = max(time, right[idx2].first + t);
                while(idx2 < right.size() and right[idx2].first <= time and passanger_cnt <= m){
                    answer[right[idx2].second] = time + t;
                    passanger_cnt++;
                    idx2++;
                }
            }else{
                time = max(time, left[idx].first);
                while(idx < left.size() and left[idx].first <= time and passanger_cnt <= m){
                    answer[left[idx].second] = time + t;
                    passanger_cnt++;
                    idx++;
                }
                direction = 1;
            }
        }else{
            if(left[idx].first > right[idx2].first){
                time = max(time, right[idx2].first);
                while(idx2 < right.size() and right[idx2].first <= time and passanger_cnt <= m){
                    answer[right[idx2].second] = time + t;
                    passanger_cnt++;
                    idx2++;
                }
            }else{
                time = max(time, left[idx].first + t);
                while(idx < left.size() and left[idx].first <= time and passanger_cnt <= m){
                    answer[left[idx].second] = time + t;
                    passanger_cnt++;
                    idx++;
                }
                direction = 0;
            }
        }
        time += t;
        passanger_cnt = 0;
    }
    
    if(idx < left.size()){
        if(direction == 1){
            time += t;
        }
        while(idx < left.size()){
            time = max(time, left[idx].first);
            while(idx < left.size() and left[idx].first <= time and passanger_cnt <= m){
                answer[left[idx].second] = time + t;
                passanger_cnt++;
                idx++;
            }
            passanger_cnt = 0;
            time += 2 * t;
        }
    }

    if(idx2 < right.size()){
        if(direction == 0){
            time += t;
        }
        while(idx2 < right.size()){
            time = max(time, right[idx2].first);
            while(idx2 < right.size() and right[idx].first <= time and passanger_cnt <= m){
                answer[right[idx2].second] = time + t;
                passanger_cnt++;
                idx2++;
            }
            passanger_cnt = 0;
            time += 2 * t;
        }
    }

    for(int i = 0; i < n; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}