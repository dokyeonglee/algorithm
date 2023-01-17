#include <iostream>
#include <vector>

using namespace std;

int dr[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> cloud(n, vector<int>(n));

    cloud[n - 2][0] = 1;
    cloud[n - 2][1] = 1;
    cloud[n - 1][0] = 1;
    cloud[n - 1][1] = 1;

    vector<vector<int>> add(n, vector<int>(n));
    
    for(int i = 0; i < m; i++){

        int d, s;
        cin >> d >> s;

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(cloud[r][c] % 10 == 1){
                    cloud[r][c]--;
                    int next_r = ((r + dr[d] * s % n) + n) % n;
                    int next_c = ((c + dc[d] * s % n) + n) % n;
                    cloud[next_r][next_c] += 10;
                    arr[next_r][next_c]++;
                }
            }
        }

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){    
                if(cloud[r][c] == 10){
                    for(int k = 2; k <= 8; k += 2){
                        int next_r = r + dr[k];
                        int next_c = c + dc[k];
                        if(next_r < 0 or  next_r >= n or next_c < 0 or next_c >= n){
                            continue;
                        }
                        if(arr[next_r][next_c] > 0){
                            add[r][c]++;
                        }
                    }
                }
            }
        }

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                arr[r][c] += add[r][c];
                add[r][c] = 0;
                if(cloud[r][c] == 0){
                    if(arr[r][c] >= 2){
                        arr[r][c] -= 2;
                        cloud[r][c] = 1;
                    }
                }else{
                    cloud[r][c] = 0;
                }
            }
        }        
    }

    int answer = 0;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            answer += arr[r][c];
        }
    }

    cout << answer;

    return 0;
}