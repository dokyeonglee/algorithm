#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    vector<int> pos(n * m + 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            pos[arr[i][j]] = i * m + j;
        }
    }

    int k;
    cin >> k;

    priority_queue<int> pq;
    
    vector<vector<bool>> visited(n, vector<bool>(m));

    for(int i = 0; i < m; i++){
        visited[0][i] = true;
        pq.push(arr[0][i]);
    }

    for(int i = 1; i < n - 1; i++){
        visited[i][0] = true;
        pq.push(arr[i][0]);
    }

    if(n > 1){
        for(int i = 0; i < m; i++){
            visited[n - 1][i] = true;
            pq.push(arr[n - 1][i]);
        }   
    }

    if(m > 1){
        for(int i = 1; i < n - 1; i++){
            visited[i][m - 1] = true;
            pq.push(arr[i][m - 1]);
        }
    }

    vector<int> answer(k);

    for(int i = 0; i < k; i++){

        int x = pq.top();
        pq.pop();

        int now = pos[x];
        int now_r = now / m;
        int now_c = now % m;

        answer[i] = now;

        for(int j = 0; j < 4; j++){

            int next_r = now_r + dr[j];
            int next_c = now_c + dc[j];

            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                continue;
            }

            if(!visited[next_r][next_c]){
                visited[next_r][next_c] = true;
                pq.push(arr[next_r][next_c]);
            }

        }
    }

    for(int i = 0; i < k; i++){
        cout << answer[i] / m + 1 << " " << answer[i] % m + 1 << "\n";
    }

    return 0;
}