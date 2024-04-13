#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(4));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> score(n);
    for(int i = 0; i < n; i++){
        score.emplace_back(-max(arr[i][0], max(arr[i][1], arr[i][2])), i);
    }

    sort(score.begin(), score.end());

    vector<vector<pair<int, int>>> position(4);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            position[i].emplace_back(-arr[j][i], j);
        }
    }

    for(int i = 0; i < 4; i++){
        sort(position[i].begin(), position[i].end());
    }

    long long answer = 0;

    for(int i = 0; i < 11; i++){
        int idx = position[0][i].second;
        for(int j = 0; j < 11; j++){
            int idx2 = position[1][j].second;
            if(idx == idx2){
                continue;
            }
            for(int k = 0; k < 11; k++){
                int idx3 = position[2][k].second;
                if(idx == idx3 or idx2 == idx3){
                    continue;
                }
                for(int l = 0; l < 11; l++){
                    int idx4 = position[3][l].second;    
                    if(idx == idx4 or idx2 == idx4 or idx3 == idx4){
                        continue;
                    }
                    long long result = -position[0][i].first + -position[1][j].first + -position[2][k].first + -position[3][l].first;
                    int cnt = 4;
                    int _idx5 = 0;
                    while(cnt < 11){
                        int idx5 = score[_idx5].second;
                        if(idx == idx5 or idx2 == idx5 or idx3 == idx5 or idx4 == idx5){
                            _idx5++;
                            continue;
                        }
                        result += -score[_idx5++].first;
                        cnt++;
                    }
                    answer = max(answer, result);
                }
            }
        }
    }


    cout << answer;

    return 0;
}