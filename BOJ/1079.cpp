#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int guilty_kill(vector<int>& guilty, vector<bool>& killed){
    int _max = 0;
    int idx = -1;
    for(int i = 0; i < killed.size(); i++){
        if(!killed[i]){
            if(_max < guilty[i]){
                _max = guilty[i];
                idx = i;
            }
        }
    }
    return idx;
}

int solve(vector<int>& guilty, vector<vector<int>>& arr, vector<bool>& killed, int eunjin, int n, int cnt){
    if(killed[eunjin] or n == 1){
        return cnt;
    }
    int result = 0;
    if(n % 2 == 0){
        for(int i = 0; i < killed.size(); i++){
            if(i != eunjin and !killed[i]){
                killed[i] = true;
                for(int j = 0; j < arr.size(); j++){
                    guilty[j] += arr[i][j];
                }
                result = max(result, solve(guilty, arr, killed, eunjin, n - 1, cnt + 1));
                for(int j = 0; j < arr.size(); j++){
                    guilty[j] -= arr[i][j];
                }
                killed[i] = false;
            }
        }
    }else{
        int idx = guilty_kill(guilty, killed);
        killed[idx] = true;
        result = max(result, solve(guilty, arr, killed, eunjin, n - 1, cnt));
        killed[idx] = false;
    }

    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> guilty(n);
    for(int i = 0; i < n; i++){
        cin >> guilty[i];
    }

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int eunjin;
    cin >> eunjin;

    vector<bool> killed(n);

    cout << solve(guilty, arr, killed, eunjin, n, 0);

    return 0;
}