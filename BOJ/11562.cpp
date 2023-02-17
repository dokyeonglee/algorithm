#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 987654321));

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int i = 0;i  < m; i++){
        int u, v, b;
        cin >> u >> v >> b;
        arr[u][v] = 0;
        arr[v][u] = b ^ 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int k;
    cin >> k;

    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        cout << arr[u][v] << "\n";
    }

    return 0;
}