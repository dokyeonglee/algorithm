#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 1e9));

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        arr[u][v] = c;
    }

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    vector<vector<pair<int, pair<int, int>>>> query(n + 1);
    for(int i = 0; i < q; i++){
        int s, k, e;
        cin >> s >> k >> e;
        query[k].emplace_back(i, make_pair(s, e));
    }

    vector<int> answer(q, 1e9);

    for(int l = 1; l <= n; l++){
        auto temp = arr;
        for(int k = 1; k <= n; k++){
            if(k == l){
                continue;
            }
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    temp[i][j] = min(temp[i][j], temp[i][k] + temp[k][j]);
                }
            }
        }
        for(auto q : query[l]){
            answer[q.first] = temp[q.second.first][q.second.second];
        }
    }

    for(int i = 0; i < q; i++){
        if(answer[i] == 1e9){
            cout << "No\n";
        }else{
            cout << answer[i] << "\n";
        }
    }

    return 0;
}