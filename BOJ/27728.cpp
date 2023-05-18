#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = n - 1; j >= 1; j--){
            arr[i][j] += arr[i][j + 1];
        }
    }

    vector<vector<int>> min_value(n + 1, vector<int>(n + 1, 987654321));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            min_value[i][j] = min(arr[i][j], min_value[i - 1][j]);
        }
    }

    while(q--){
        int r, c, l;
        cin >> r >> c >> l;
        int answer = arr[r][c];
        for(int i = c; i <= n; i++){
            answer = min(answer, arr[r][c] - arr[r][i] + min_value[r - l][i]);
        }
        cout << answer << "\n";
    }


    return 0;
}