#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        vector<vector<int>> arr(n + 1, vector<int>(n + 1));
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < n + 1; j++){
                cin >> arr[i][j];
            }
        }

        for(int k = 0; k < n + 1; k++){
            for(int i = 0; i < n + 1; i++){
                for(int j = 0; j < n + 1; j++){
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }

        int answer = 987654321;

        vector<int> p(n);
        for(int i = 0; i < n; i++){
            p[i] = i + 1;
        }

        do{
            int now = 0;
            int result = 0;
            for(int i = 0; i < n; i++){
                result += arr[now][p[i]];
                now = p[i];
            }
            result += arr[now][0];
            answer = min(answer, result);
        }while(next_permutation(p.begin(), p.end()));

        cout << answer << "\n";
    }

    return 0;
}