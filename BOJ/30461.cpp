#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            arr[i][j] += arr[i - 1][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            arr[i][j] += arr[i - 1][j - 1];
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << arr[a][b] << "\n";
    }

    return 0;
}