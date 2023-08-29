#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string,int > team_idx;
    string team1, team2;

    for(int i = 0; i < 4; i++){
        cin >> team1;
        team_idx[team1] = i;
    }

    vector<pair<int, int>> match(6);
    vector<vector<double>> win_draw_lose(6, vector<double>(3));

    for(int i = 0; i < 6; i++){

        cin >> team1 >> team2;
        cin >> win_draw_lose[i][0] >> win_draw_lose[i][1] >> win_draw_lose[i][2];

        match[i] = make_pair(team_idx[team1], team_idx[team2]);
    }

    vector<double> answer(4);

    for(int i = 0; i < 729; i++){

        vector<int> score(4);

        int temp = i;
        double p = 1;

        for(int j = 0; j < 6; j++){
            if(temp % 3 == 0){
                p *= win_draw_lose[j][0];
                score[match[j].first] += 3;
            }else if(temp % 3 == 1){
                p *= win_draw_lose[j][1];
                score[match[j].first] += 1;
                score[match[j].second] += 1;
            }else{
                p *= win_draw_lose[j][2];
                score[match[j].second] += 3;
            }
            temp /= 3;
        }

        vector<vector<int>> score_cnt(10);
        for(int i = 0; i < 4; i++){
            score_cnt[score[i]].push_back(i);
        }

        int cnt = 0;

        for(int i = 9; i >= 0; i--){
            for(int j = 0; j < score_cnt[i].size(); j++){
                answer[score_cnt[i][j]] += min(p, p * (2 - cnt) / score_cnt[i].size());
            }
            cnt += score_cnt[i].size();
            if(cnt >= 2){
                break;
            }
        }

    }

    cout << fixed;
    cout.precision(10);

    for(int i = 0; i < 4; i++){
        cout << answer[i] << "\n";
    }


    return 0;
}