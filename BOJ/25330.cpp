#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<pair<int, int>>& dungeons, int idx, int current_hp, int cumulative_damage, int people){
    if(current_hp == 0 or idx == dungeons.size()){
        return people;
    }
    int result = people;
    for(int i = idx; i < dungeons.size(); i++){
        if(cumulative_damage + dungeons[i].first <= current_hp){
            result = max(result, dfs(dungeons, i + 1, current_hp - cumulative_damage - dungeons[i].first, cumulative_damage + dungeons[i].first, people + dungeons[i].second));
        }else{
            break;
        }
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> dungeons(n);
    for(auto& dugeon : dungeons){
        cin >> dugeon.first;
    }

    for(auto& dugeon : dungeons){
        cin >> dugeon.second;
    }

    sort(dungeons.begin(), dungeons.end());

    cout << dfs(dungeons, 0, k, 0, 0);

    return 0;

}