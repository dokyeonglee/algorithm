#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            if(x == 1){
                arr[i].push_back(j);
            }
        }
    }

    int col = 0;

    int answer = 0;

    for(int i = 0; i < n; i++){
        if(!arr[i].empty()){
            answer++;
            col = arr[i].back();
            for(int j = i + 1; j < n; j++){
                if(!arr[j].empty()){
                    auto it = lower_bound(arr[j].begin(), arr[j].end(), col);
                    if(it == arr[j].end()){
                        continue;
                    }
                    col = arr[j].back();
                    arr[j].erase(it, arr[j].end());
                }
            }
        }
    }

    cout << answer;

    return 0;

}