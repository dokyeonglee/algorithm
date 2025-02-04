#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, p, q;
        cin >> n >> p >> q;

        vector<int> arr(n);
        for(auto& a : arr){
            cin >> a;
        }

        vector<vector<int>> distance(p + 1, vector<int>(p + 1, 1e9));

        while(q--){
            int u, v, c;
            cin >> u >> v >> c;
            distance[u][v] = min(distance[u][v], c);
            distance[v][u] = distance[u][v];
        }

        for(int i = 1; i <= p; i++){
            distance[i][i] = 0;
        }

        for(int k = 1; k <= p; k++){
            for(int i = 1; i <= p; i++){
                for(int j = 1; j <= p; j++){
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }

        int idx = -1;
        long long min_sum_of_distance_square = 1e18;

        for(int i = 1; i <= p; i++){
            long long sum_of_distance_square = 0;
            for(auto& a : arr){
                if(distance[i][a] == 1e9){
                    sum_of_distance_square = 1e18;
                    break;
                }
                sum_of_distance_square += distance[i][a] * distance[i][a];
            }
            if(min_sum_of_distance_square > sum_of_distance_square){
                idx = i;
                min_sum_of_distance_square = sum_of_distance_square;
            }
        }

        cout << idx << " " << min_sum_of_distance_square << "\n";

    }

    return 0;

}