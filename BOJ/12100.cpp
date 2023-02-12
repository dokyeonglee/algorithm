#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void down(vector<vector<int>>& arr){
    for(int i = 0; i < arr[0].size(); i++){
        vector<int> v;
        for(int j = arr.size() - 1; j >= 0; j--){
            if(arr[j][i]){
                if(v.size() and v.back() == arr[j][i]){
                    v.back() *= -2;
                }else{
                    v.push_back(arr[j][i]);
                }
            }
        }
        for(int j = 0; j < v.size(); j++){
            arr[arr.size() - 1 - j][i] = abs(v[j]);
        }
        for(int j = v.size(); j < arr.size(); j++){
            arr[arr.size() - 1 - j][i] = 0;
        }
    }
}

void right(vector<vector<int>>& arr){
    for(int i = 0; i < arr.size(); i++){
        vector<int> v;
        for(int j = arr[0].size() - 1; j >= 0; j--){
            if(arr[i][j]){
                if(v.size() and v.back() == arr[i][j]){
                    v.back() *= -2;
                }else{
                    v.push_back(arr[i][j]);
                }
            }
        }
        for(int j = 0; j < v.size(); j++){
            arr[i][arr.size() - 1 - j] = abs(v[j]);
        }
        for(int j = v.size(); j < arr[0].size(); j++){
            arr[i][arr.size() - 1 - j] = 0;
        }
    }
}

void up(vector<vector<int>>& arr){
    for(int i = 0; i < arr[0].size(); i++){
        vector<int> v;
        for(int j = 0; j < arr.size(); j++){
            if(arr[j][i]){
                if(v.size() and v.back() == arr[j][i]){
                    v.back() *= -2;
                }else{
                    v.push_back(arr[j][i]);
                }
            }
        }
        for(int j = 0; j < v.size(); j++){
            arr[j][i] = abs(v[j]);
        }
        for(int j = v.size(); j < arr.size(); j++){
            arr[j][i] = 0;
        }
    }
}

void left(vector<vector<int>>& arr){
    for(int i = 0; i < arr.size(); i++){
        vector<int> v;
        for(int j = 0; j < arr[0].size(); j++){
            if(arr[i][j]){
                if(v.size() and v.back() == arr[i][j]){
                    v.back() *= -2;
                }else{
                    v.push_back(arr[i][j]);
                }
            }
        }
        for(int j = 0; j < v.size(); j++){
            arr[i][j] = abs(v[j]);
        }
        for(int j = v.size(); j < arr[0].size(); j++){
            arr[i][j] = 0;
        }
    }
}

void move(vector<vector<int>>& arr, int dir){
    if(dir == 0){
        down(arr);
    }else if(dir == 1){
        right(arr);
    }else if(dir == 2){
        up(arr);
    }else{
        left(arr);
    }
}

void solve(vector<vector<int>>& arr, int depth){

    int _max = 0;

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            _max = max(_max, arr[i][j]);
        }
    }

    answer = max(answer, _max);

    if(depth == 5){
        return;
    }

    if(answer >= _max << (5 - depth)){
        return;
    }

    for(int i = 0; i < 4; i++){
        auto temp = arr;
        move(temp, i);
        if(temp == arr){
            continue;
        }
        solve(temp, depth + 1);
    }

}

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

    solve(arr, 0);

    cout << answer;

    return 0;
}