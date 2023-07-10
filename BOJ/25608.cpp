#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> psum(n, vector<int>(m + 1));
    vector<int> left(n);
    vector<int> right(n);

    int answer = 0;

    for(int i = 0; i < n; i++){
        int result = 0;
        for(int j = 1; j <= m; j++){
            cin >> psum[i][j];
            result = max(result, 0) + psum[i][j];
            answer = max(answer, result);
            psum[i][j] += psum[i][j - 1];
            left[i] = max(left[i], psum[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            right[i] = max(right[i], psum[i][m] - psum[i][j - 1]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int result = 0;
            for(int k = 0; k < n; k++){
                if(k != i and k != j and psum[k][m] > 0){
                    result += psum[k][m];
                }
            }
            answer = max(answer, result + left[i] + right[j]);
            answer = max(answer, result + left[j] + right[i]);
        }
    }

    cout << answer;

    return 0;
}