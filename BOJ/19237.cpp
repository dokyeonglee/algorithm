#include <iostream>
#include <vector>

using namespace std;

int dr[] = {0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, -1, 1};

int move(vector<vector<pair<int, int>>>& arr, vector<pair<int, int>>& sharks, vector<int>& directions, vector<vector<vector<int>>>& priority, vector<bool>& remain, int k){
    int cnt = 0;
    for(int i = 1; i < sharks.size(); i++){
        if(remain[i]){
            cnt++;
            int d = directions[i];
            auto& p = priority[i][d];
            bool check = true;
            for(int j = 0; j < 4; j++){
                int next_r = sharks[i].first + dr[p[j]];
                int next_c = sharks[i].second + dc[p[j]];
                if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr.size()){
                    continue;
                }
                if(arr[next_r][next_c].first == 0){
                    arr[next_r][next_c].first = -i;
                    arr[next_r][next_c].second = k + 1;
                    sharks[i] = make_pair(next_r, next_c);
                    directions[i] = p[j];
                    check = false;
                    break;
                }else if(arr[next_r][next_c].first < 0){
                    remain[i] = false;
                    cnt--;
                    check = false;
                    break;
                }
            }
            if(check and remain[i]){
                for(int j = 0; j < 4; j++){
                    int next_r = sharks[i].first + dr[p[j]];
                    int next_c = sharks[i].second + dc[p[j]];
                    if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr.size()){
                        continue;
                    }
                    if(arr[next_r][next_c].first == i){
                        arr[next_r][next_c].second = k + 1;
                        sharks[i] = make_pair(next_r, next_c);
                        directions[i] = p[j];
                        break;
                    }
                }    
            }
        }
    }
    return cnt;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> arr(n, vector<pair<int, int>>(n));
    vector<pair<int, int>> sharks(m + 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j].first;
            if(arr[i][j].first > 0){
                arr[i][j].second = k;
                sharks[arr[i][j].first] = make_pair(i, j);
            }
        }
    }

    vector<int> directions(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> directions[i];
    }

    vector<vector<vector<int>>> priority(m + 1, vector<vector<int>>(5, vector<int>(4)));
    for(int x = 1; x <= m; x++){
        for(int i = 1; i <= 4; i++){
            for(int j = 0; j < 4; j++){
                cin >> priority[x][i][j];
            }
        }
    }

    vector<bool> remain(m + 1, true);
    
    for(int i = 0; i < 1000; i++){
        if(move(arr, sharks, directions, priority, remain, k) == 1){
            cout << i + 1;
            return 0;
        }
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                arr[r][c].first = abs(arr[r][c].first);
                if(arr[r][c].second != 0){
                    if(--arr[r][c].second == 0){
                        arr[r][c].first = 0;
                    }
                }
            }
        }
    }

    cout << -1;

    return 0;
}