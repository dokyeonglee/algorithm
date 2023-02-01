#include <iostream>
#include <vector>

using namespace std;

void rotate_disk(vector<int>& idx, int x, int k, int m){
    for(int i = x; i < idx.size(); i += x){
        idx[i] = (idx[i] + k) % m;
    }
}

void inner_disk(vector<vector<int>>& arr){

    int n = arr.size() - 1;
    int m = arr[0].size();

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(abs(arr[i][j]) == abs(arr[i][(j + 1) % m])){
                arr[i][j] = -abs(arr[i][j]);
                arr[i][(j + 1) % m] = -abs(arr[i][(j + 1) % m]);
            }
        }
    }

}

void inter_disk(vector<vector<int>>& arr, vector<int>& idx){

    int n = arr.size() - 1;
    int m = arr[0].size();
    
    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++){
            if(abs(arr[j][(idx[j] + i) % m]) == abs(arr[j + 1][(idx[j + 1] + i) % m])){
                arr[j][(idx[j] + i) % m] = -abs(arr[j][(idx[j] + i) % m]);
                arr[j + 1][(idx[j + 1] + i) % m] = -abs(arr[j + 1][(idx[j + 1] + i) % m]);
            }
        }
    }

}

pair<int, int> erase(vector<vector<int>>& arr){

    int n = arr.size() - 1;
    int m = arr[0].size();
    int sum = 0;
    int cnt = 0;
    bool check = false;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] > 0){
                sum += arr[i][j];
                cnt++;
            }else if(arr[i][j] < 0){
                check = true;
                arr[i][j] = 0;
            }
        }
    }

    if(check){
        return make_pair(-sum, cnt);
    }else{
        return make_pair(sum, cnt);
    }
 
}

void increase_or_decrease(vector<vector<int>>& arr, int sum, int cnt){

    int n = arr.size() - 1;
    int m = arr[0].size();

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] > 0){
                if(arr[i][j] * cnt > sum){
                    arr[i][j]--;
                }else if(arr[i][j] * cnt < sum){
                    arr[i][j]++;
                }
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> arr(n + 1, vector<int>(m));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> idx(n + 1);

    for(int a = 0; a < t; a++){

        int x, d, k;
        cin >> x >> d >> k;

        if(d == 0){
            k = m - k;
        }

        rotate_disk(idx, x, k, m);
        inner_disk(arr);
        inter_disk(arr, idx);
        auto p = erase(arr);

        if(p.first > 0){
            increase_or_decrease(arr, p.first, p.second);
        }

    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            answer += arr[i][j];
        }
    }

    cout << answer;

    return 0;
}