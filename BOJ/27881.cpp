#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(4 * n + 1);
    long long sum = 0;

    for(int i = 2; i <= 4 * n; i++){
        cin >> arr[i];
        sum += arr[i];
        arr[i] += arr[i - 1];
    }

    int x;
    cin >> x;

    sum += x;

    vector<vector<int>> station(4, vector<int>(3));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            cin >> station[i][j];
        }
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){

        int x;
        cin >> x;

        long long answer = 1e18;

        for(int j = 0; j < 4; j++){
            int u = x;
            int v = n * (j + 1);
            if(u < v){
                swap(u, v);
            }
            long long dist = min(arr[u] - arr[v], sum - (arr[u] - arr[v]));
            for(int k = 0; k < 3; k++){
                answer = min(answer, dist + station[j][k]);
            }
        }
        cout << answer << "\n";
    }

    return 0;
}