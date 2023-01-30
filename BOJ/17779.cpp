#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_one(vector<vector<int>>& arr, int r, int c, int d1, int d2){

    int result = 0;

    for(int i = 0; i < r; i++){
        for(int j = 0; j <= c; j++){
            result += arr[i][j];
        }
    }

    for(int i = 0; i < d1; i++){
        for(int j = 0; j < c - i; j++){
            result += arr[r + i][j];
        }
    }

    return result;
}

int get_two(vector<vector<int>>& arr, int r, int c, int d1, int d2){

    int result = 0;

    for(int i = 0; i <= r; i++){
        for(int j = c + 1; j < arr[0].size(); j++){
            result += arr[i][j];
        }
    }

    for(int i = 0; i < d2; i++){
        for(int j = c + 2 + i; j < arr[0].size(); j++){
            result += arr[r + 1 + i][j];
        }
    }

    return result;
}

int get_three(vector<vector<int>>& arr, int r, int c, int d1, int d2){

    int result = 0;

    for(int i = 0; i < d2; i++){
        for(int j = 0; j < c - d1 + i; j++){
            result += arr[r + d1 + i][j];
        }
    }

    for(int i = r + d1 + d2; i < arr.size(); i++){
        for(int j = 0; j < c - d1 + d2; j++){
            result += arr[i][j];
        }
    }

    return result;
}

int get_four(vector<vector<int>>& arr, int r, int c, int d1, int d2){

    int result = 0;

    for(int i = 0; i < d1; i++){
        for(int j = c + d2 - i; j < arr[0].size(); j++){
            result += arr[r + d2 + 1 + i][j];
        }
    }

    for(int i = r + d1 + d2 + 1; i < arr.size(); i++){
        for(int j = c - d1 + d2; j < arr[0].size(); j++){
            result += arr[i][j];
        }
    }

    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    int sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    int answer = 1e9;

    for(int i = 0; i < n - 2; i++){
        for(int j = 1; j < n - 1; j++){
            for(int d1 = 1; i + d1 < n and d1 <= j; d1++){
                for(int d2 = 1; i + d1 + d2 < n and j + d2 < n; d2++){
                    vector<int> brr(5);
                    brr[0] = get_one(arr, i, j, d1, d2);
                    brr[1] = get_two(arr, i, j, d1, d2);
                    brr[2] = get_three(arr, i, j, d1, d2);
                    brr[3] = get_four(arr, i, j, d1, d2);
                    brr[4] = sum - brr[0] - brr[1] - brr[2] - brr[3];
                    sort(brr.begin(), brr.end());
                    answer = min(answer, brr[4] - brr[0]);
                }
            }
        }
    }

    cout << answer;

    return 0;
}