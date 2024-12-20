#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<vector<int>> scores(4, vector<int>(n + 1));
    vector<vector<int>> times(4, vector<int>(n + 1));

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= n; j++){
            cin >> scores[i][j];
        }
    }

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= n; j++){
            cin >> times[i][j];
        }
    }

    vector<vector<pair<int, int>>> psum(4);

    for(int i = 1; i <= 3; i++){
        psum[i].emplace_back(0, 0);
        int score_sum = 0;
        int time_sum = 0;
        for(int j = 1; j <= n; j++){
            score_sum += scores[i][j];
            time_sum += times[i][j];
            if(time_sum <= t){
                if(psum[i].back().second < score_sum){
                    psum[i].emplace_back(time_sum, score_sum);
                }
            }else{
                break;
            }
        }
    }

    int answer = 0;

    for(int i = 0; i < psum[3].size(); i++){
        int p1 = 0;
        int p2 = psum[2].size() - 1;
        while(p1 < psum[1].size() and p2 >= 0){
            int r = t - psum[1][p1].first - psum[2][p2].first;
            if(r >= psum[3][i].first){
                answer = max(answer, psum[1][p1].second + psum[2][p2].second + psum[3][i].second);
                p1++;
            }else{
                p2--;
            }
        }
    }

    cout << answer;

    return 0;
}