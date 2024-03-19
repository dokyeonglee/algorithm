#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 987654321));
    vector<pair<int, pair<int, int>>> edges(m);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        arr[u][v] = min(arr[u][v], c);
        arr[v][u] = min(arr[u][v], c);
        edges[i] = make_pair(c, make_pair(u, v));
    }

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int answer = 1e9;

    for(int i = 1; i <= n; i++){
        int result = 0;
        for(auto& e : edges){
            int u = e.second.first;
            int v = e.second.second;
            int c = e.first;
            result = max(result, arr[i][u] + arr[i][v] + c);
        }
        answer = min(answer, result);
    }

    cout << fixed;
    cout.precision(1);
    cout << answer / 2.0;

    return 0;
}