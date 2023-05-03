#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> arr(3, vector<int>(3));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> row(3);
    vector<int> col(3);
    vector<pair<int, int>> pos;
    vector<int> row_zero_cnt(3);
    vector<int> col_zero_cnt(3);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] == 0){
                pos.push_back(make_pair(i, j));
                row_zero_cnt[i]++;
                col_zero_cnt[j]++;
            }else{
                row[i] += arr[i][j];
                col[j] += arr[i][j];
            }
        }
    }

    if(arr[0][0] == 0 and arr[1][1] == 0 and arr[2][2] == 0){
        int s = (row[0] + row[1] + row[2]) / 2;
        arr[0][0] = s - row[0];
        arr[1][1] = s - row[1];
        arr[2][2] = s - row[2];
    }else if(arr[0][2] == 0 and arr[1][1] == 0 and arr[2][0] == 0){
        int s = (row[0] + row[1] + row[2]) / 2;
        arr[0][2] = s - row[0];
        arr[1][1] = s - row[1];
        arr[2][0] = s - row[2];
    }else{
        int sum = max(arr[0][0] + arr[1][1] + arr[2][2], arr[0][2] + arr[1][1] + arr[2][0]);
        for(int i = 0; i < 3; i++){
            sum = max(sum, max(row[i], col[i]));
        }
        int idx = -1;
        for(int i = 0; i < pos.size(); i++){
            if(row_zero_cnt[pos[i].first] == 2 and col_zero_cnt[pos[i].second] == 2){
                idx = i;
                continue;
            }
            int& a = arr[pos[i].first][pos[i].second];
            a = sum - max(row[pos[i].first], col[pos[i].second]);
            row[pos[i].first] += a;
            col[pos[i].second] += a;
        }
        if(idx != -1){
            int& a = arr[pos[idx].first][pos[idx].second];
            a = sum - row[pos[idx].first];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}