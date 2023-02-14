#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 987654321));
    vector<vector<int>> answer(n + 1, vector<int>(n + 1));

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        arr[u][v] = c;
        arr[v][u] = c;
        answer[u][v] = v;
        answer[v][u] = u;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    answer[i][j] = answer[i][k];
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                cout << "- ";
            }else{
                cout << answer[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}