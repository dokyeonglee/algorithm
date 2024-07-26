#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int x = 0; x < min(n, m) / 2; x++){

        vector<int> v;

        for(int r = x; r < n - x; r++){
            v.push_back(arr[r][x]);
        }
        for(int c = x + 1; c < m - x; c++){
            v.push_back(arr[n - 1 - x][c]);
        }
        for(int r = n - 2 - x; r >= x; r--){
            v.push_back(arr[r][m - 1 - x]);
        }
        for(int c = m - 2 - x; c > x; c--){
            v.push_back(arr[x][c]);
        }

        int r = s % v.size();
        int idx = (v.size() - r) % v.size();

        for(int r = x; r < n - x; r++){
            arr[r][x] = v[idx++ % v.size()];
        }
        for(int c = x + 1; c < m - x; c++){
            arr[n - 1 - x][c] = v[idx++ % v.size()];
        }
        for(int r = n - 2 - x; r >= x; r--){
            arr[r][m - 1 - x] = v[idx++ % v.size()];
        }
        for(int c = m - 2 - x; c > x; c--){
            arr[x][c] = v[idx++ % v.size()];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}