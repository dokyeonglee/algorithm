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
    int sz = left.size();
    int sz2 = right.size();

    left.push_back(make_pair(987654321, 987654321));
    right.push_back(make_pair(987654321, 987654321));

    while(idx < sz or idx2 < sz2){
        
        time = max(time, min(left[idx].first, right[idx2].first));
        for(int i = 0; i < m and idx < sz and left[idx].first <= time; i++){
            answer[left[idx].second] = time + t;
            idx++;
        }
        time += t;

        time = max(time, min(left[idx].first, right[idx2].first));
        for(int i = 0; i < m and idx2 < sz2 and right[idx2].first <= time; i++){
            answer[right[idx2].second] = time + t;
            idx2++;
        }
        time += t;
    }
    
    for(int i = 0; i < n; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}