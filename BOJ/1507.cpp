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

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j and i != k and j != k){
                    if(arr[i][j] == arr[i][k] + arr[k][j]){
                        arr[i][j] = 987654321;
                    }
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            if(arr[i][j] != 987654321){
                answer += arr[i][j];
            }
        }
    }

    cout << answer / 2;

    return 0;
}