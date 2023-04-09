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
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] |= arr[i][k] & arr[k][j];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int answer = n - 1;
        for(int j = 1; j <= n; j++){
            answer -= arr[i][j] | arr[j][i];
        }
        cout << answer << "\n";
    }

    return 0;
}