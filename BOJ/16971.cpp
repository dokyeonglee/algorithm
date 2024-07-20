#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long answer = 0;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> row_sum(n);
    vector<int> col_sum(m);

    for(int i = 0; i < n; i++){
        for(int j = 1; j < m - 1; j++){
            row_sum[i] += 2 * arr[i][j];
        }
        row_sum[i] += arr[i][0] + arr[i][m - 1];
    }

    for(int i = 0; i < m; i++){
        for(int j = 1; j < n - 1; j++){
            col_sum[i] += 2 * arr[j][i];
        }
        col_sum[i] += arr[0][i] + arr[n - 1][i];
    }

    for(int i = 1; i < n - 1; i++){
        answer += 2 * row_sum[i];
    }

    answer += row_sum[0] + row_sum[n - 1];

    int exchange = 0;

    if(n > 2){
        exchange = max(exchange, max(row_sum[0], row_sum[n - 1]) - *min_element(row_sum.begin() + 1, row_sum.end() - 1));
    }

    if(m > 2){
        exchange = max(exchange, max(col_sum[0], col_sum[m - 1]) - *min_element(col_sum.begin() + 1, col_sum.end() - 1));
    }
    
    answer += exchange;

    cout << answer;

    return 0;
}