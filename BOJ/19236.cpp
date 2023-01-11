#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

int result;

pair<int, int> get_next(pair<int, int>& fish, int direction){
    return make_pair(fish.first + dr[direction], fish.second + dc[direction]);
}

bool in_range(pair<int, int>& p){
    return p.first >= 0 and p.first < 4 and p.second >= 0 and p.second < 4;
}

void fish_move(vector<vector<int>>& arr, vector<pair<int, int>>& fishes, vector<int>& directions,vector<bool>& visited){
    for(int i = 1; i <= 16; i++){
        if(!visited[i]){
            auto next = get_next(fishes[i], directions[i]);
            while(!in_range(next) or arr[next.first][next.second] == 0){
                directions[i] = (directions[i] + 1) % 8;
                next = get_next(fishes[i], directions[i]);
            }
            swap(arr[fishes[i].first][fishes[i].second], arr[next.first][next.second]);
            if(arr[fishes[i].first][fishes[i].second] > 0){
                fishes[arr[fishes[i].first][fishes[i].second]] = fishes[i];
            }
            fishes[i] = next;
        }
    }
}

int dfs(vector<vector<int>>& arr, vector<pair<int, int>>& fishes, vector<int>& directions, vector<bool>& visited, int sum){

    fish_move(arr, fishes, directions, visited);

    result = max(result, sum);

    auto& shark = fishes[0];
    int shark_direction = directions[0];

    arr[shark.first][shark.second] = -1;

    auto temp_arr(arr);
    auto temp_fishes(fishes);
    auto temp_directions(directions);

    auto next = get_next(shark, shark_direction);

    while(in_range(next)){
        int fish_number = arr[next.first][next.second];
        if(fish_number > 0 and !visited[fish_number]){

            visited[fish_number] = true;
            shark = next;
            directions[0] = directions[fish_number];
            arr[shark.first][shark.second] = 0;

            dfs(arr, fishes, directions, visited, sum + fish_number);

            visited[fish_number] = false;
            fishes = temp_fishes;
            directions = temp_directions;
            arr = temp_arr;
            
        }
        next = get_next(next, shark_direction);
    }

    return 0;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> arr(4, vector<int>(4));

    vector<pair<int, int>> fishes(17);
    vector<int> directions(17);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int fish_number, direction;
            cin >> fish_number >> direction;
            arr[i][j] = fish_number;
            fishes[fish_number] = make_pair(i, j);
            directions[fish_number] = direction - 1;
        }
    }

    fishes[0] = fishes[arr[0][0]];
    directions[0] = directions[arr[0][0]];
    
    vector<bool> visited(17);
    visited[arr[0][0]] = true;

    int answer = arr[0][0];

    arr[0][0] = 0;

    dfs(arr, fishes, directions, visited, 0);

    cout << answer + result;

    return 0;
}