#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    vector<vector<int>> like(n * n + 1, vector<int>(n * n + 1));

    for(int i = 0; i < n * n; i++){
        int x;
        cin >> x;
        for(int j = 0; j < 4; j++){
            int y;
            cin >> y;
            like[x][y] = 1;
        }

        int max_blank_cnt = -1;
        int max_like_cnt = -1;
        pair<int, int> result;

        for(int r = 1; r <= n; r++){
            for(int c = 1; c <= n; c++){
                if(arr[r][c] == 0){
                    int blank_cnt = 0;
                    int like_cnt = 0;
                    for(int k = 0; k < 4; k++){
                        int next_r = r + dr[k];
                        int next_c = c + dc[k];
                        if(next_r < 1 or next_r > n or next_c < 1 or next_c > n){
                            continue;
                        }
                        int y = arr[next_r][next_c];
                        if(y == 0){
                            blank_cnt++;
                        }else{
                            like_cnt += like[x][y];
                        }
                    }
                    if(max_like_cnt < like_cnt){
                        max_like_cnt = like_cnt;
                        max_blank_cnt = blank_cnt;
                        result = make_pair(r, c);
                    }else if(max_like_cnt == like_cnt and max_blank_cnt < blank_cnt){
                        max_blank_cnt = blank_cnt;
                        result = make_pair(r, c);
                    }
                }
            }
        }
        
        arr[result.first][result.second] = x;
    }

    int ten[] = {0, 1, 10, 100, 1000};
    int answer = 0;

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            int x = arr[r][c];
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int next_r = r + dr[k];
                int next_c = c + dc[k];
                if(next_r < 1 or next_r > n or next_c < 1 or next_c > n){
                    continue;
                }
                int y = arr[next_r][next_c];
                cnt += like[x][y];
            }
            answer += ten[cnt];
        }
    }

    cout << answer;
    
    return 0;
}