#include <iostream>
#include <vector>

using namespace std;

int dr[] = {0, 1};
int dc[] = {1, 0};

pair<int, int> dfs(vector<vector<char>>& arr, int r, int c, int value){

    int n = arr.size();

    if(r == n - 1 and c == n - 1){
        return make_pair(value, value);
    }

    pair<int, int> result = make_pair(-1e9, 1e9);

    for(int i = 0; i < 2; i++){
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if(next_r >= n or next_c >= n){
            continue;
        }
        int next_value = value;
        if(arr[r][c] == '+'){
            next_value = value + (arr[next_r][next_c] - '0');
        }else if(arr[r][c] == '-'){
            next_value = value - (arr[next_r][next_c] - '0');
        }else if(arr[r][c] == '*'){
            next_value = value * (arr[next_r][next_c] - '0');
        }
        auto temp = dfs(arr, next_r, next_c, next_value);
        result.first = max(result.first, temp.first);
        result.second = min(result.second, temp.second);
    }

    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<char>> arr(n, vector<char>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    auto answer = dfs(arr, 0, 0, arr[0][0] - '0');

    cout << answer.first << " " << answer.second;

    return 0;
}