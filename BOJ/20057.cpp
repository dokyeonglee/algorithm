#include <iostream>
#include <vector>

using namespace std;

int d[2][11] = {{0, -2, -1, -1, -1, 0, 1, 1, 1, 2, 0}, {-1, -1, -2, -1, 0, -3, -2, -1, 0, -1, -2}};
int ratio[] = {0, 2, 10, 7, 1, 5, 10, 7, 1, 2, 0};

void solve(vector<vector<int>>& arr, int r, int c, int idx1, int idx2, int sign){
    int next_r = r + sign * d[idx1][0];
    int next_c = c + sign * d[idx2][0];
    int sand = arr[next_r][next_c];
    arr[next_r][next_c] = 0;
    int remain_sand = sand;
    for(int i = 1; i < 11; i++){
        next_r = r + sign * d[idx1][i];
        next_c = c + sign * d[idx2][i];
        arr[next_r][next_c] += sand * ratio[i] / 100;
        remain_sand -= sand * ratio[i] / 100;
    }
    arr[next_r][next_c] += remain_sand;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 10, vector<int>(n + 10));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i + 3][j + 3];
        }
    }

    int r = n / 2 + 3;
    int c = n / 2 + 3;
    
    int x = 1;

    while(r != 3){
        for(int i = 0; i < x; i ++){
            solve(arr, r, c--, 0, 1, 1);
        }
        for(int i = 0; i < x; i++){
            solve(arr, r++, c, 1, 0, -1);
        }
        for(int i = 0; i < x + 1; i++){
            solve(arr, r, c++, 0, 1, -1);
        }
        for(int i = 0; i < x + 1; i++){
            solve(arr, r--, c, 1, 0, 1);
        }
        x += 2;
    }

    for(int i = 0; i < x - 1; i++){
        solve(arr, r, c--, 0, 1, 1);
    }
    
    int answer = 0;

    for(int i = 0; i < n + 6; i++){
        for(int j = 0; j < n + 6; j++){
            if(i < 3 or j < 3 or i >= n + 3 or j >= n + 3){
                answer += arr[i][j];
            }
        }
    }

    cout << answer;

    return 0;
}