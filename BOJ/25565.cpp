#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> arr(n + 2, vector<int>(m + 2));
    vector<pair<int, int>> seed;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                seed.emplace_back(i, j);
            }
        }
    }

    if(seed.size() == 2 * k){
        cout << 0;
    }else{

        int cross_r = -1;
        int cross_c = -1;

        for(auto& s : seed){
            int x = arr[s.first - 1][s.second] + arr[s.first + 1][s.second];
            int y = arr[s.first][s.second - 1] + arr[s.first][s.second + 1];
            if(x and y){
                cross_r = s.first;
                cross_c = s.second;
            }
        }

        int overlap = 2 * k - seed.size();
        cout << overlap << "\n";

        if(cross_r != -1){
            cout << cross_r << " " << cross_c;
        }else{
            for(int i = seed.size() - k; i < k; i++){
                cout << seed[i].first << " " << seed[i].second << "\n";
            }
        }

    }

    return 0;

}