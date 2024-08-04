#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1));    

    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        for(int j = 1; j <= m; j++){
            arr[i][j] = '1' - str[j - 1];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }

    int answer = 0;

    for(int i = 1; i <= m; i++){
        for(int j = i; j <= m; j++){
            int result = 0;
            for(int k = 1; k <= n; k++){
                int sum = arr[k][j] - arr[k - 1][j] - arr[k][i - 1] + arr[k - 1][i - 1];
                if(sum == j - i + 1){
                    result += sum;
                }else{
                    result = 0;
                }
                answer = max(answer, result);
            }
        }
    }

    cout << answer;

    return 0;
}