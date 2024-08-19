#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;

void dfs(vector<vector<bool>>& arr, int now){

    for(int i = 0; i < arr.size(); i++){
        if(arr[now][i]){
            arr[now][i] = false;
            arr[i][now] = false;
            dfs(arr, i);
        }
    }

    answer.push_back(now + 1);

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<bool>> arr(n, vector<bool>(n, true));
    
    for(int i = 0; i < n; i++){
        arr[i][i] = false;
    }

    dfs(arr, 0);

    for(int i = answer.size() - 1; i >= 0; i--){
        cout << "a" << answer[i] << " ";
    }

    return 0;
}