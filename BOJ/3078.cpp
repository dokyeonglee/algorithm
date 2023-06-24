#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> arr(21);

    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        arr[name.size()].push_back(i);
    }

    long long answer = 0;

    for(int i = 2; i <= 20; i++){
        if(arr[i].size() > 1){
            queue<int> q;
            for(int j = 0; j < arr[i].size(); j++){
                while(!q.empty() and arr[i][j] - q.front() > k){
                    answer += q.size() - 1;
                    q.pop();
                }
                q.push(arr[i][j]);
            }
            answer += q.size() * (q.size() - 1) / 2;
        }
    }

    cout << answer;

    return 0;
}