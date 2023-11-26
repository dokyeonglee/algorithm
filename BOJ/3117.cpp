#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    m--;

    vector<vector<int>> parent(31, vector<int>(k + 1));

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= k; i++){
        cin >> parent[0][i];
    }

    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= k; j++){
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    for(int i = 30; i >= 0; i--){
        if(m & (1 << i)){
            for(int& x : arr){
                x = parent[i][x];
            }
        }
    }

    for(int& x : arr){
        cout << x << " ";
    }

    return 0;
}