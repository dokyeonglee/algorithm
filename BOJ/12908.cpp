#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<long long>> arr(8, vector<long long>(8, 2e9 + 1));

    vector<pair<int, int>> pos(8);

    cin >> pos[0].first >> pos[0].second;
    cin >> pos[1].first >> pos[1].second;

    for(int i = 2; i < 8; i += 2){
        cin >> pos[i].first >> pos[i].second >> pos[i + 1].first >> pos[i + 1].second;
        arr[i][i + 1] = 10;
        arr[i + 1][i] = 10;
    }

    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j++){
            long long dist = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
            arr[i][j] = min(arr[i][j], dist);
        }    
    }

    for(int k = 0; k < 8; k++){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    cout << arr[0][1];

    return 0;
}