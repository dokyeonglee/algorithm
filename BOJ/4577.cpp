#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

string solve(vector<string>& arr, pair<int, int>& character, string& command, int number_of_box){

    int dir;
    int cnt = 0;

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            if(arr[i][j] == 'B'){
                cnt++;
            }
        }
    }

    for(int i = 0; i < command.size(); i++){

        if(number_of_box == cnt){
            return "complete"; 
        }

        if(command[i] == 'U'){
            dir = 0;
        }else if(command[i] == 'R'){
            dir = 1;
        }else if(command[i] == 'D'){
            dir = 2;
        }else{
            dir = 3;
        }

        int next_r = character.first + dr[dir];
        int next_c = character.second + dc[dir];

        if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size() or arr[next_r][next_c] == '#'){
            continue;
        }

        if(arr[next_r][next_c] == 'b' or arr[next_r][next_c] == 'B'){

            int next_box_r = next_r + dr[dir];
            int next_box_c = next_c + dc[dir];

            if(next_box_r < 0 or next_box_r >= arr.size() or next_box_c < 0 or next_box_c >= arr[0].size() or arr[next_box_r][next_box_c] == '#' or arr[next_box_r][next_box_c] == 'b' or arr[next_box_r][next_box_c] == 'B'){
                continue;
            }

            if(arr[next_r][next_c] == 'B'){
                cnt--;
            }

            if(arr[next_box_r][next_box_c] == '+'){
                arr[next_box_r][next_box_c] = 'B';
                cnt++;
            }else{
                arr[next_box_r][next_box_c] = 'b';
            }

        }

        if(arr[next_r][next_c] == '+' or arr[next_r][next_c] == 'B'){
            arr[next_r][next_c] = 'W';
        }else{
            arr[next_r][next_c] = 'w';
        }

        if(arr[character.first][character.second] == 'W'){
            arr[character.first][character.second] = '+';
        }else{
            arr[character.first][character.second] = '.';
        }

        character = make_pair(next_r, next_c);
        
    }

    if(number_of_box == cnt){
        return "complete"; 
    }

    return "incomplete";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while(1){

        int n, m;
        cin >> n >> m;

        if(n == 0){
            break;
        }
        
        vector<string> arr(n);
        pair<int, int> character;
        int number_of_box = 0;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 'w' or arr[i][j] == 'W'){
                    character = make_pair(i, j);
                }else if(arr[i][j] == 'b' or arr[i][j] == 'B'){
                    number_of_box++;
                }
            }
        }

        string command;
        cin >> command;

        cout << "Game " << t++ << ": " << solve(arr, character, command, number_of_box) << "\n";
        for(int i = 0; i < n; i++){
            cout << arr[i] << "\n";
        }
    }

    return 0;
}