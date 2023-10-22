#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        arr[u][v] = 1;
        //arr[v][u] = -1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][k] == 1 and arr[k][j] == 1){
                    arr[i][j] = 1;
                }
            }
        }
    }

    vector<pair<int, int>> answer(n + 1, make_pair(1, n));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == 1 and arr[j][i] == 1){
                cout << -1;
                return 0;
            }
            if(arr[i][j] == 1){
                answer[i].second--;    
            }else if(arr[j][i] == 1){
                answer[i].first++;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << answer[i].first << " " << answer[i].second << "\n";
    }

    return 0;
}