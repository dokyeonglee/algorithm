#include <iostream>
#include <queue>

using namespace std;

int dr[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dc[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<string> board(r);

    queue<pair<int, int>> crazy_arduinoes;

    pair<int, int> jongsu_arduino;

    for(int i = 0; i < r; i++){
        cin >> board[i];
        for(int j = 0; j < c; j++){
            if(board[i][j] == 'R'){
                crazy_arduinoes.emplace(i, j);
            }else if(board[i][j] == 'I'){
                jongsu_arduino = make_pair(i, j);
            }
        }
    }

    string command;
    cin >> command;

    int answer = 0;

    vector<vector<int>> cnt(r, vector<int>(c));

    for(auto& x : command){

        answer++;

        board[jongsu_arduino.first][jongsu_arduino.second] = '.';

        jongsu_arduino.first += dr[x - '0'];
        jongsu_arduino.second += dc[x - '0'];

        if(board[jongsu_arduino.first][jongsu_arduino.second] == 'R'){
            cout << "kraj " << answer;
            return 0;
        }else{
            board[jongsu_arduino.first][jongsu_arduino.second] = 'I';
        }

        int sz = crazy_arduinoes.size();

        if(sz == 0){
            continue;
        }

        while(sz--){

            auto crazy_arduino = crazy_arduinoes.front();
            crazy_arduinoes.pop();

            board[crazy_arduino.first][crazy_arduino.second] = '.';

            int min_dist = 1e9;
            int idx = 0;

            for(int i = 1; i <= 9; i++){
                int dist = abs(crazy_arduino.first + dr[i] - jongsu_arduino.first) + abs(crazy_arduino.second + dc[i] - jongsu_arduino.second);
                if(dist < min_dist){
                    min_dist = dist;
                    idx = i;
                }
            }

            crazy_arduino.first += dr[idx];
            crazy_arduino.second += dc[idx];

            cnt[crazy_arduino.first][crazy_arduino.second]++;

        }

        if(cnt[jongsu_arduino.first][jongsu_arduino.second]){
            cout << "kraj " << answer;
            return 0;
        }else{
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(cnt[i][j] == 1){
                        crazy_arduinoes.emplace(i, j);
                        board[i][j] = 'R';
                    }
                    cnt[i][j] = 0;
                }
            }  
        }

    }

    for(int i = 0; i < r; i++){
        cout << board[i] << "\n";
    }

    return 0;
}