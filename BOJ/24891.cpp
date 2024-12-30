#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<string>& arr, vector<string>& answer, vector<bool>& visited, int cnt){
    if(cnt == answer.size()){
        return true;
    }
    for(int i = 0; i < visited.size(); i++){
        if(!visited[i]){
            bool check = false;
            for(int j = 0; j < cnt; j++){
                if(arr[i][j] != answer[j][cnt]){
                    check = true;
                    break;
                }
            }
            if(check){
                continue;
            }
            visited[i] = true;
            answer[cnt] = arr[i];
            if(dfs(arr, answer, visited, cnt + 1)){
                return true;
            }
            visited[i] = false;
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, n;
    cin >> l >> n;

    vector<string> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    sort(arr.begin(), arr.end());

    vector<string> answer(l);
    vector<bool> visited(n);

    if(!dfs(arr, answer, visited, 0)){
        cout << "NONE";
    }else{
        for(int i = 0; i < l; i++){
            cout << answer[i] << "\n";
        }
    }

    return 0;

}