#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer;

void dfs(vector<vector<int>>& arr, vector<bool>& visited, int idx, int sum){

    if(idx == arr.size()){
        answer = max(answer, sum);
        return;
    }

    for(int i = 0; i < arr.size(); i++){
        if(!visited[i] and arr[idx][i]){
            visited[i] = true;
            dfs(arr, visited, idx + 1, sum + arr[idx][i]);
            visited[i] = false;
        }
    }
        
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        vector<vector<int>> arr(11, vector<int>(11));
        
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < 11; j++){
                cin >> arr[i][j];
            }
        }

        vector<bool> visited(11);

        answer = 0;

        dfs(arr, visited, 0, 0);

        cout << answer << "\n";

    }

    return 0;
}