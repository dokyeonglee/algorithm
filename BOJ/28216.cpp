#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long inf = 1e18;

long long item(vector<pair<int, long long>>& line, int low, int high){

    auto it = upper_bound(line.begin(), line.end(), make_pair(high, inf)) - 1 - line.begin();
    auto it2 = lower_bound(line.begin(), line.end(), make_pair(low, 0ll)) - line.begin();

    if(it < it2){
        return 0;
    }

    if(it2 != 0){
        return line[it].second - line[it2 - 1].second;
    }else{
        return line[it].second;
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, long long>>> vertical(2e5 + 1);
    vector<vector<pair<int, long long>>> horizontal(2e5 + 1);

    for(int i = 0; i < n; i++){
        int x, y, w;
        cin >> x >> y >> w;
        vertical[x].emplace_back(y, w);
        horizontal[y].emplace_back(x, w);
    }

    for(int i = 1; i <= 2e5; i++){
        if(vertical[i].size() > 0){
            sort(vertical[i].begin(), vertical[i].end());
        }
    }

    for(int i = 1; i <= 2e5; i++){
        if(horizontal[i].size() > 0){
            sort(horizontal[i].begin(), horizontal[i].end());
        }
    }

    for(int i = 1; i <= 2e5; i++){
        for(int j = 1; j < vertical[i].size(); j++){
            vertical[i][j].second += vertical[i][j - 1].second;
        }
    }

    for(int i = 1; i <= 2e5; i++){
        for(int j = 1; j < horizontal[i].size(); j++){
            horizontal[i][j].second += horizontal[i][j - 1].second;
        }
    }

    long long answer = 0;

    int x = 1;
    int y = 1;

    while(q--){

        int d, v;
        cin >> d >> v;

        if(d == 0){
            answer += item(horizontal[y], x + 1, x + v);
            x += v;
        }else if(d == 1){
            answer += item(vertical[x], y + 1, y + v);
            y += v;
        }else if(d == 2){
            answer += item(horizontal[y], x - v, x - 1);
            x -= v;
        }else{
            answer += item(vertical[x], y - v, y - 1);
            y -= v;
        }

    }
    
    cout << answer;

    return 0;
}