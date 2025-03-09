#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int move_belt(vector<vector<int>>& arr){
    int result = 0;
    int b = arr.size();
    if(arr[b - 1][0] == -1){
        result++;
    }
    for(int i = 1; i < b; i++){
        arr[b - 1][i - 1] = arr[b - 1][i];
    }
    for(int i = b - 2; i >= 0; i--){
        arr[i + 1][b - 1] = arr[i][b - 1];
    }
    for(int i = b - 2; i >= 0; i--){
        arr[0][i + 1] = arr[0][i];
    }
    return result;
}

void put_gift(vector<vector<int>>& arr, int& remain){    
    if(remain > 0){
        remain--;
        arr[0][0] = -1;
    }else{
        arr[0][0] = 0;
    }
}

bool pickable(vector<vector<int>>& arr, vector<pair<pair<int, int>, pair<int, int>>>& employees, int r, int c){
    for(int i = 0; i < 4; i++){
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
            continue;
        }
        if(arr[next_r][next_c] > 0 and employees[arr[next_r][next_c]].second.second == 0){
            arr[r][c] = 0;
            employees[arr[next_r][next_c]].second.second = employees[arr[next_r][next_c]].second.first;
            return 1;
        }
    }
    return 0;
}

int pick_gift(vector<vector<int>>& arr, vector<pair<pair<int, int>, pair<int, int>>>& employees){
    int b = arr.size();
    int result = 0;
    for(int i = 0; i < b; i++){
        if(arr[b - 1][i] == -1){
            result += pickable(arr, employees, b - 1, i);
        }
    }
    for(int i = b - 2; i >= 0; i--){
        if(arr[i][b - 1] == -1){
            result +=pickable(arr, employees, i, b - 1);
        }
    }
    for(int i = b - 2; i >= 0; i--){
        if(arr[0][i] == -1){
            result += pickable(arr, employees, 0, i);
        }
    }
    return result;
}

void wrap_gift(vector<pair<pair<int, int>, pair<int, int>>>& employees){
    for(int i = 1; i < employees.size(); i++){
        if(employees[i].second.second != 0){
            employees[i].second.second--;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;

    int b, n, m;
    cin >> b >> n >> m;

    vector<vector<int>> arr(b, vector<int>(b));

    vector<pair<pair<int, int>, pair<int, int>>> employees(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> employees[i].first.first >> employees[i].first.second >> employees[i].second.first;
        arr[employees[i].first.first][employees[i].first.second] = i;
    }

    int remain = m;

    int x;

    while(m > 0){
        m -= move_belt(arr);
        put_gift(arr, remain);
        x = pick_gift(arr, employees);
        wrap_gift(employees);
        answer += x;
        m -= x;
    }

    cout << answer;

    return 0;

}