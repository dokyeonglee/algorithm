#include <iostream>
#include <vector>

using namespace std;

int shape1(vector<vector<int>>& arr, int r, int c){
    int result = -1e9;
    if(r + 3 < arr.size()){
        result = max(result, arr[r][c] + arr[r + 1][c] + arr[r + 2][c] + arr[r + 3][c]);
    }
    if(c + 3 < arr[r].size()){
        result = max(result, arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r][c + 3]);
    }
    return result;
}

int shape2(vector<vector<int>>& arr, int r, int c){
    int result = -1e9;
    if(r + 1 < arr.size() and c + 2 < arr[r].size()){
        result = max(result, arr[r][c] + arr[r][c + 1] + arr[r + 1][c + 1] + arr[r + 1][c + 2]);
    }
    if(r + 2 < arr.size() and c > 0){
        result = max(result, arr[r][c] + arr[r + 1][c] + arr[r + 1][c - 1] + arr[r + 2][c - 1]);
    }
    return result;
}

int shape3(vector<vector<int>>& arr, int r, int c){
    int result = -1e9;
    if(r + 1 < arr.size() and c + 2 < arr[r].size()){
        result = max(result, arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r + 1][c + 2]);
    }
    if(r + 2 < arr.size() and c > 0){
        result = max(result, arr[r][c] + arr[r + 1][c] + arr[r + 2][c] + arr[r + 2][c - 1]);
    }
    if(r + 1 < arr.size() and c + 2 < arr[r].size()){
        result = max(result, arr[r][c] + arr[r + 1][c] + arr[r + 1][c + 1] + arr[r + 1][c + 2]);
    }
    if(r + 2 < arr.size() and c > 0){
        result = max(result, arr[r][c] + arr[r][c - 1] + arr[r + 1][c - 1] + arr[r + 2][c - 1]);
    }
    return result;
}

int shape4(vector<vector<int>>& arr, int r, int c){
    int result = -1e9;
    if(r + 1 < arr.size() and c + 2 < arr[r].size()){
        result = max(result, arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r + 1][c + 1]);
    }
    if(r + 2 < arr.size() and c > 0){
        result = max(result, arr[r][c] + arr[r + 1][c] + arr[r + 2][c] + arr[r + 1][c - 1]);
    }
    if(r > 0 and c + 2 < arr[r].size()){
        result = max(result, arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r - 1][c + 1]);
    }
    if(r + 2 < arr.size() and c + 1 < arr[r].size()){
        result = max(result, arr[r][c] + arr[r + 1][c] + arr[r + 2][c] + arr[r + 1][c + 1]);
    }
    return result;
}

int shape5(vector<vector<int>>& arr, int r, int c){
    int result = -1e9;
    if(r + 1 < arr.size() and c + 1 < arr[r].size()){
        result = arr[r][c] + arr[r + 1][c] + arr[r][c + 1] + arr[r + 1][c + 1];
    }
    return result;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while(1){

        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        vector<vector<int>> arr(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        int answer = -1e9;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int result = shape1(arr, i, j);
                result = max(result, shape2(arr, i, j));
                result = max(result, shape3(arr, i, j));
                result = max(result, shape4(arr, i, j));
                result = max(result, shape5(arr, i, j));
                answer = max(answer, result);
            }
        }

        cout << t++ << ". " << answer << "\n";

    }

    return 0;

}