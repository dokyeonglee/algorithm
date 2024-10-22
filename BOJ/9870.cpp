#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<vector<long long>> arr(n + 1, vector<long long>(n + 1, 1e18));

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        arr[u][v] = c;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int number_of_valid_route = 0;
    long long sum_of_cost = 0;

    while(q--){

        int a, b;
        cin >> a >> b;

        long long min_cost = 1e18;

        for(int i = 1; i <= k; i++){
            min_cost = min(min_cost, arr[a][i] + arr[i][b]);
        }

        if(min_cost != 1e18){
            number_of_valid_route++;
            sum_of_cost += min_cost;
        }

    }

    cout << number_of_valid_route << "\n";
    cout << sum_of_cost;

    return 0;
}