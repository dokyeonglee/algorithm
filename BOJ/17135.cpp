#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int attack(int N, vector<int> archor, int D, vector<pair<int, int>> enemy, int cnt){
    
    if(enemy.size() == 0){
        return cnt;
    }
    
    vector<int> distance(3, 987654321);
    vector<int> pos(3, -1);
    
    for(int i = 0; i < enemy.size(); i++){
        for(int j = 0; j < 3; j++){
            int dist = abs(enemy[i].first - N) + abs(enemy[i].second - archor[j]); 
            if(dist <= distance[j]){
                if(dist == distance[j]){
                    if(enemy[pos[j]].second > enemy[i].second){
                        pos[j] = i;
                    }
                }else{
                    pos[j] = i;
                }
                distance[j] = dist;
            }
        }
    }
    
    for(int i = 0; i < 3; i++){
        if(enemy[pos[i]].first != -1 and distance[i] <= D){
            enemy[pos[i]].first = -1;
            enemy[pos[i]].second = -1;
            cnt++;
        }
    }
    
    vector<pair<int, int>> temp;
    for(pair<int, int> p : enemy){
        if(p.first != -1 and p.first + 1 < N){
            temp.push_back(make_pair(p.first + 1, p.second));
        }
    }
    
    return attack(N, archor, D, temp, cnt);
}

int solve(int N, int M, int D, vector<pair<int, int>> enemy){
    
    int answer = 0;
    
    for(int i = 0; i < M; i++){
        for(int j = i + 1; j < M; j++){
            for(int k = j + 1; k < M; k++){
                answer = max(answer, attack(N, {i, j, k}, D, enemy, 0));
            }
        }
    }
    
    return answer;
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, D;
    cin >> N >> M >> D;
    
    vector<vector<int>> board(N, vector<int>(M));         
    vector<pair<int, int>> enemy;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                enemy.push_back(make_pair(i, j));
            }
        }
    }
    
    int answer = solve(N, M, D, enemy);
    cout << answer;
    
    return 0;
}
