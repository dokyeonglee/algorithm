#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int cnt = (min(n, m) + 1) / 2;

    for(int i = 0; i < cnt; i++){
        int l = 2 * (m - 2 * i) + 2 * (n - 2 * i - 2);
        vector<int> temp;
        for(int j = i; j < m - i; j++){
            temp.push_back(arr[i][j]);
        }
        for(int j = i + 1; j < n - i; j++){
            temp.push_back(arr[j][m - 1 - i]);
        }
        for(int j = m - 1 - i - 1; j >= i; j--){
            temp.push_back(arr[n - 1 - i][j]);
        }
        for(int j = n - 1 - i - 1; j > i; j--){
            temp.push_back(arr[j][i]);
        }
        int t = r % l;
        int x = 0;
        for(int j = i; j < m - i; j++){
            arr[i][j] = temp[(x++ + t) % l];
        }
        for(int j = i + 1; j < n - i; j++){
            arr[j][m - 1 - i] = temp[(x++ + t) % l];
        }
        for(int j = m - 1 - i - 1; j >= i; j--){
            arr[n - 1 - i][j] = temp[(x++ + t) % l];
        }
        for(int j = n - 1 - i - 1; j > i; j--){
            arr[j][i] = temp[(x++ + t) % l];
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