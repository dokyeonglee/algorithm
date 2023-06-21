#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 987654321));

    for(int i = 0; i < m; i++){
        int u, v, h;
        cin >> u >> v >> h;
        arr[u][v] = h;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], max(arr[i][k], arr[k][j]));
            }
        }
    }

    while(t--){
        int s, e;
        cin >> s >> e;
        int answer = arr[s][e];
        if(answer == 987654321){
            answer = -1;
        }
        cout << answer << "\n";
    }    

    return 0;
}