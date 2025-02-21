#include <iostream>
#include <vector>

using namespace std;

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

    vector<vector<int>> answer;

    vector<bool> visited(n);

    for(int i = 0; i < n; i++){
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        vector<int> result{i};
        for(int j = 0; j < n; j++){
            if(i == j or arr[i][j]){
                continue;
            }
            if(visited[j]){
                cout << 0;
                return 0;   
            }
            visited[j] = true;
            result.push_back(j);
        }
        if(result.size() == 1){
            cout << 0;
            return 0;
        }
        for(auto& x : result){
            for(auto& y : result){
                if(arr[x][y]){
                    cout << 0;
                    return 0;
                }
            }
        }
        answer.push_back(result);
    }

    cout << answer.size() << "\n";
    for(auto& v : answer){
        for(auto& x : v){
            cout << x + 1 << " ";
        }
        cout << "\n";
    }

    return 0;

}