#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; i++){
        arr[i][i] = 1;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = -1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][k] == 1 and arr[k][j] == 1){
                    arr[i][j] = 1;
                }else if(arr[i][k] == -1 and arr[k][j] == -1){
                    arr[i][j] = -1;
                }
            }
        }
    }

    int answer = 0;

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(arr[i][j] != 0){
                cnt++;
            }
        }
        if(cnt == n){
            answer++;
        }
    }

    cout << answer;

    return 0;
}