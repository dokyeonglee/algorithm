#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    long long answer = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int x = 0;
            for(int k = 0; k < n; k++){
                x += arr[i][k] * arr[k][j];
            }
            answer += x * (x - 1);
        }
    }

    answer *= 2;

    cout << answer;

    return 0;
}